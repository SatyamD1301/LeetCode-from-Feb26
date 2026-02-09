class Solution {
public:
    double ans = 0.0;

    void dfs(int src, int parent, vector<vector<int>>& adj,
             int t, int target, double prob) {

        if (t == 0) {
            if (src == target) ans = prob;
            return;
        }

        int children = 0;
        for (int next : adj[src]) {
            if (next != parent) children++;
        }

        
        if (children == 0) {
            if (src == target) ans = prob;
            return;
        }

        for (int next : adj[src]) {
            if (next != parent) {
                dfs(next, src, adj, t - 1, target, prob / children);
            }
        }
    }

    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        vector<vector<int>> adj(n + 1);

        for (auto edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        dfs(1, 0, adj, t, target, 1.0);
        return ans;
    }
};
