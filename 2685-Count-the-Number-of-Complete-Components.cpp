class Solution {
public:
    void dfs(int node, vector<vector<int>>& adj, vector<bool>& vis, vector<int>& component, int& edgeCount) {
        vis[node] = true;
        component.push_back(node);
        edgeCount += adj[node].size(); // count all adjacent edges (will be double-counted)
        for (int neighbor : adj[node]) {
            if (!vis[neighbor]) {
                dfs(neighbor, adj, vis, component, edgeCount);
            }
        }
    }

    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        for (auto& edge : edges) {
            int u = edge[0], v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> vis(n, false);
        int count = 0;

        for (int i = 0; i < n; ++i) {
            if (!vis[i]) {
                vector<int> component;
                int edgeCount = 0;
                dfs(i, adj, vis, component, edgeCount);

                int k = component.size();
                // In an undirected graph, each edge is counted twice
                if (edgeCount / 2 == k * (k - 1) / 2) {
                    count++;
                }
            }
        }

        return count;
    }
};
