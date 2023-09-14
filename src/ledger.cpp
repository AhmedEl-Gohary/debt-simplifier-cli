#include "../include/ledger.h"

#include <iostream>
#include <string>

Ledger::Ledger(int nodes) {
    adjacencyList.assign(nodes, std::vector<int>());
    capacity.assign(nodes, std::vector<int>(nodes, 0));
}

void Ledger::addName(const std::string& name) {
    if (nameToId.find(name) == end(nameToId)) {
        nameToId[name] = nodeCount;
        idToName[nodeCount++] = name;
    }
}

void Ledger::addEntry(const std::string& debtor, const std::string& creditor, int money) {
    addName(debtor);
    addName(creditor);
    int debtorId = nameToId[debtor];
    int creditorId = nameToId[creditor];
    adjacencyList[debtorId].push_back(creditorId);
    adjacencyList[creditorId].push_back(debtorId);
    capacity[debtorId][creditorId] = money;
    entries.emplace_back(debtor, creditor, money);
    threshold += money;
}

std::ostream& operator<<(std::ostream& os, Ledger& ledger) {
    for (const auto& [debtor, creditor, _] : ledger.entries) {
        int u = ledger.nameToId[debtor];
        int v = ledger.nameToId[creditor];
        if (ledger.capacity[u][v] == 0) continue;
        os << ledger.idToName[u] << " owes " << "$" << std::to_string(ledger.capacity[u][v]) << " to " << ledger.idToName[v] << "." << std::endl;
    }
    return os;
}





