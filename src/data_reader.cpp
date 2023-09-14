#include "../include/ledger.h"
#include "../include/data_reader.h"

#include <fstream>
#include <string>
#include <unordered_set>

int DataReader::readEntries(const std::string& inputFileName, std::vector<std::tuple<std::string, std::string, int>>& entries) {
    std::ifstream inputFile(inputFileName);

    int partakers = 0;
    std::unordered_set<std::string> set;
    std::string debtor, creditor, moneyStr;
    while (inputFile >> debtor >> creditor >> moneyStr) {
        for (char c : moneyStr) {
            if (!isdigit(c)) {
                throw std::invalid_argument("Invalid moneyFormat exception");
            }
        }
        if (moneyStr.size() > 7) {
            throw std::invalid_argument("Invalid moneyAmount exception");
        }
        int money = std::stoi(moneyStr);
        entries.emplace_back(debtor, creditor, money);
        if (set.find(debtor) == end(set)) {
            partakers++;
            set.insert(debtor);
        }
        if (set.find(creditor) == end(set)) {
            partakers++;
            set.insert(creditor);
        }
    }

    inputFile.close();
    return partakers;
}
