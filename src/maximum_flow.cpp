#include "../include/maximum_flow.h"

#include <functional>
#include <limits>

MaximumFlow::MaximumFlow(Ledger& ledger) : ledger(ledger) {
    visited.assign(ledger.nodeCount, -1);
}

// Maximum flow using Ford-Fulkerson algorithm + capacity scaling heuristic
// O(m^2 * log(threshold))
int MaximumFlow::maxFlow(int source, int sink) {

    std::function<int(int, int, int)> dfs = [&](int v, int flow, int cap) -> int {
        if (v == sink) return flow;
        visited[v] = curTime;

        for (int u : ledger.adjacencyList[v]) {
            if (ledger.capacity[v][u] < cap || visited[u] == curTime) continue;
            int minCapacity = dfs(u, std::min(flow, ledger.capacity[v][u]), cap);

            if (minCapacity > 0) {
                ledger.capacity[v][u] -= minCapacity;
                ledger.capacity[u][v] += minCapacity;
                return minCapacity;
            }
        }

        return 0;
    };

    int maxFlowValue = 0, cap = ledger.threshold;
    for (int minCapacity; cap > 0; cap /= 2) {
        do {
            curTime++;
            minCapacity = dfs(source, std::numeric_limits<int>::max() / 2, cap);
            maxFlowValue += minCapacity;
        } while (minCapacity > 0);
    }

    return maxFlowValue;
}
