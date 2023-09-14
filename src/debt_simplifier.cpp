#include "../include/data_reader.h"
#include "../include/data_writer.h"
#include "../include/ledger.h"
#include "../include/maximum_flow.h"

#include <vector>
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc < 2) {
        std::cerr << "Too few arguments. Arguments should be <ledger_input_file> <optional: ledger_output_file>" << std::endl;
        exit(-1);
    }

    try {
        std::vector<std::tuple<std::string, std::string, int>> entries;

        DataReader dataReader;
        int partakers = dataReader.readEntries(argv[1], entries);

        std::vector<std::pair<int, int>> edges;

        // Initialize the ledger
        Ledger ledger{partakers};
        for (const auto& [debtor, creditor, money] : entries) {
            ledger.addEntry(debtor, creditor, money);
            edges.emplace_back(ledger.nameToId[debtor], ledger.nameToId[creditor]);
        }

        int activeEdges = 0;
        std::vector exist(partakers, std::vector(partakers, false));
        for (const auto& [u, v] : edges) {
            exist[u][v] = true;
            exist[v][u] = true;
            activeEdges++;
        }
        int initialNoOfTransactions = activeEdges;

        while (activeEdges > 0) {
            for (const auto& [u, v] : edges) {
                if (!exist[u][v]) continue;
                exist[u][v] = false;
                exist[v][u] = false;
                activeEdges--;

                // source is u, sink is v

                // O(m^2 * Log(threshold))
                MaximumFlow fordFulkerson = MaximumFlow{ledger};
                int maxFlow = fordFulkerson.maxFlow(u, v);

                for (int i = 0; i < ledger.nodeCount; i++) {
                    for (int j = 0; j < ledger.nodeCount; j++) {
                        ledger.capacity[i][j] = 0;
                    }
                }

                for (const auto& [debtor, creditor] : edges) {
                    if (fordFulkerson.ledger.capacity[debtor][creditor] == 0) {
                        if (exist[debtor][creditor]) activeEdges--;
                        exist[debtor][creditor] = false;
                        exist[creditor][debtor] = false;
                    }
                    ledger.capacity[debtor][creditor] = fordFulkerson.ledger.capacity[debtor][creditor];
                }

                ledger.capacity[u][v] = maxFlow;
            }
        }

        int finalNoOfTransactions = 0;
        for (const auto& [debtor, creditor] : edges) {
            if (ledger.capacity[debtor][creditor] != 0) finalNoOfTransactions++;
        }

        DataWriter dataWriter;
        if (argc == 3) {
            dataWriter.writeLedger(argv[2], ledger);
        } else {
            dataWriter.writeLedger(ledger);
        }

        std::cout << "Debt Simplification Complete" << std::endl;
        std::cout << "Number of transactions decreased from " << initialNoOfTransactions << " to " << finalNoOfTransactions << std::endl;

    } catch (const std::exception& e) {
        std::cerr << "Error: " << e.what() << std::endl;
        exit(-1);
    }
}
