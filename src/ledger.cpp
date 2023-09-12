#include "../include/ledger.h"

#include <iostream>
#include <string>

Ledger::Ledger(int nodes) {
    m_adjacencyList.resize(nodes);
}

void Ledger::addName(std::string& name) {
    if (m_nameToId.find(name) == end(m_nameToId)) {
        m_nameToId[name] = ++nodeCount;
        m_idToName[nodeCount] = name;
    }
}

void Ledger::addEntry(std::string& debtor, std::string& creditor, int money) {
    Edge edge{m_nameToId[creditor], money};
    addName(debtor);
    m_adjacencyList[m_nameToId[debtor]].emplace_back(edge);
    m_entries.emplace_back(debtor, creditor, money);
}

std::ostream& operator<<(std::ostream& os, const Ledger& ledger) {
    for (const auto& [debtor, creditor, money] : ledger.m_entries) {
        os << debtor << "owes " << "$" << std::to_string(money) << "to " << creditor << ".\n";
    }
    return os;
}





