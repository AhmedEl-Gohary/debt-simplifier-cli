#include <string>

#ifndef EDGE_H
#define EDGE_H

class Edge {
private:
    const int m_creditorId{};
    const int m_money{};

public:
    Edge(int, int);

    int getCreditorId() { return m_creditorId; }
    int getMoney() { return m_money; }

};

#endif //EDGE_H
