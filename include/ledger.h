#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <tuple>

#ifndef LEDGER_H
#define LEDGER_H

class Ledger {
public:
    std::unordered_map<std::string, int> nameToId{};
    std::unordered_map<int, std::string> idToName{};
    std::vector<std::vector<int>> adjacencyList{};
    std::vector<std::tuple<std::string, std::string, int>> entries{};
    std::vector<std::vector<int>> capacity{};
    int nodeCount{0}, threshold{0};

    explicit Ledger(int);

    void addName(const std::string&);

    void addEntry(const std::string&, const std::string&, int);

    friend std::ostream& operator<<(std::ostream&, Ledger&);

};

#endif //LEDGER_H

