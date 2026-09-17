class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<bool> visit(n, false);

        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int cnt = 0;
        for(int node = 0; node<n; node++){
            if(!visit[node]){
                dfs(node, adjList, visit);
                cnt++;
            }
        }

        return cnt;
    }

    void dfs(int node, vector<vector<int>>& adjList, vector<bool>& visit){
        visit[node] = true;

        for(int nei: adjList[node]){
            if(!visit[nei]){
                dfs(nei, adjList, visit);
            }
        }
    }
};