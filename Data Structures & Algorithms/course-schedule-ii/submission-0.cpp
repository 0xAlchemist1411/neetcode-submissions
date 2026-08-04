class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        //Build the graph
        for(auto& p: prerequisites){
            adj[p[1]].push_back(p[0]);
            indegree[p[0]]++;
        }

        queue<int> q;

        // Push all nodes having indegree 0
        for(int i=0;i<numCourses;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        vector<int> ans;

        while(!q.empty()){
            auto node = q.front();
            q.pop();

            ans.push_back(node);

            for(auto& n: adj[node]){
                indegree[n]--;

                if(indegree[n] == 0){
                    q.push(n);
                }
            }
        }

        if(ans.size() != numCourses){
            return {};
        }

        return ans;
    }
};
