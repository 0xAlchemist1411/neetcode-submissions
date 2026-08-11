class Solution {
public:
    bool dfs(int node, int parent, unordered_set<int> &visit, vector<vector<int>> &adj){
        if(visit.count(node)){ // current node is in the set
            return false;
        }

        visit.insert(node);

        for(int nei: adj[node]){
            if(nei == parent){ // skip the parent as thats already traversed
                continue;
            }

            if(!dfs(nei, node, visit, adj)){ // nei becomes new node and node becomes parent
                return false;
            }
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size() > n-1){
            return false;
        }

        vector<vector<int>> adj(n);

        for(auto& e: edges){
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        unordered_set<int> visit;

        if(dfs(0, -1, visit, adj) && visit.size() == n){
            return true;
        }

        return false;
    }
};