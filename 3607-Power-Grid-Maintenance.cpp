

class DSU {
public:
    vector<int> parent, rank;
    DSU(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        for (int i = 1; i <= n; i++) parent[i] = i;
    }
    
    int find(int x) {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void unite(int a, int b) {
        a = find(a);
        b = find(b);
        if (a == b) return;
        if (rank[a] < rank[b]) parent[a] = b;
        else if (rank[a] > rank[b]) parent[b] = a;
        else {
            parent[b] = a;
            rank[a]++;
        }
    }
};

class Solution {
public:
    vector<int> processQueries(int c, vector<vector<int>>& connections, vector<vector<int>>& queries) {
        DSU dsu(c);

        // Build connections (union the connected stations)
        for (auto &edge : connections)
            dsu.unite(edge[0], edge[1]);
        
        // Map root -> set of online stations
        unordered_map<int, set<int>> componentStations;
        vector<bool> online(c + 1, true);
        
        for (int i = 1; i <= c; i++) {
            int root = dsu.find(i);
            componentStations[root].insert(i);
        }

        vector<int> result;
        
        for (auto &q : queries) {
            int type = q[0];
            int x = q[1];
            int root = dsu.find(x);
            
            if (type == 1) {
                if (online[x]) {
                    result.push_back(x);
                } else {
                    if (!componentStations[root].empty()) {
                        result.push_back(*componentStations[root].begin()); // smallest online station
                    } else {
                        result.push_back(-1);
                    }
                }
            } else { // [2, x]: station goes offline
                if (online[x]) {
                    online[x] = false;
                    componentStations[root].erase(x);
                }
            }
        }
        
        return result;
    }
};
