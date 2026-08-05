#include <vector>
#include <queue>

class Solution {
public:
    std::vector<int> remainingMethods(int n, int k, std::vector<std::vector<int>>& invocations) {
        // Build adjacency list for method invocations
        std::vector<std::vector<int>> adj(n);
        for (const auto& inv : invocations) {
            adj[inv[0]].push_back(inv[1]);
        }
        
        // BFS to find all suspicious methods starting from 'k'
        std::vector<bool> isSuspicious(n, false);
        std::queue<int> q;
        q.push(k);
        isSuspicious[k] = true;
        
        while (!q.empty()) {
            int u = q.front();
            q.pop();
            for (int v : adj[u]) {
                if (!isSuspicious[v]) {
                    isSuspicious[v] = true;
                    q.push(v);
                }
            }
        }
        
        // Check if any non-suspicious method invokes a suspicious method
        for (const auto& inv : invocations) {
            int u = inv[0];
            int v = inv[1];
            if (!isSuspicious[u] && isSuspicious[v]) {
                // Cannot remove suspicious methods; return all methods
                std::vector<int> allMethods(n);
                for (int i = 0; i < n; ++i) {
                    allMethods[i] = i;
                }
                return allMethods;
            }
        }
        
        // Collect all non-suspicious methods
        std::vector<int> remaining;
        for (int i = 0; i < n; ++i) {
            if (!isSuspicious[i]) {
                remaining.push_back(i);
            }
        }
        return remaining;
    }
};
