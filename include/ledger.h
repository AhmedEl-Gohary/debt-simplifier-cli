#include "edge.h"

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>

#ifndef LEDGER_H
#define LEDGER_H

class Ledger {
private:
    std::unordered_map<std::string, int> m_nameToId{};
    std::unordered_map<int, std::string> m_idToName{};
    std::vector<std::vector<Edge>> m_adjacencyList{};
    std::vector<std::tuple<std::string, std::string, int>> m_entries{};

public:
    std::unordered_map<std::string, int> getNameToId() {
        return m_nameToId;
    }

    std::unordered_map<int, std::string> getIdToName() {
        return m_idToName;
    }

    std::vector<std::vector<Edge>> getAdjacencyList() {
        return m_adjacencyList;
    }

    std::vector<std::tuple<std::string, std::string, int>> getEntries() {
        return m_entries;
    }

    inline static int nodeCount = -1;

    explicit Ledger(int);

    void addName(std::string&);

    void addEntry(std::string&, std::string&, int);

    friend std::ostream& operator<<(std::ostream&, const Ledger&);

};

#endif //LEDGER_H
