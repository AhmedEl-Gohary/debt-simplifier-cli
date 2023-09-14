#include "ledger.h"

#ifndef MAXIMUM_FLOW_H
#define MAXIMUM_FLOW_H

class MaximumFlow {
public:
    Ledger ledger;
    int curTime{0};
    std::vector<int> visited;

    explicit MaximumFlow(Ledger&);

    int maxFlow(int source, int sink);

};

#endif //MAXIMUM_FLOW_H
