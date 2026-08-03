class Solution {
    unordered_map<int, vector<int>> preMap;
    unordered_set<int> visited;
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        for(auto pre: prerequisites){
            preMap[pre[0]].push_back(pre[1]);
        }

        for(int i=0;i<numCourses;i++){
            if(dfs(i) == false){ // return false if cycle is detected
                return false;
            }
        }

        return true; // otherwise return true
    }

    bool dfs(int crs){
        if(visited.count(crs)){
            // Already visited, and cycle detected
            return false;
        }

        if(preMap[crs].empty()){ // if no prerequisites for that course
            return true;
        }

        visited.insert(crs);
        for(int pre: preMap[crs]){ // traverse the prerequisites for that course
            if(dfs(pre) == false){
                return false;
            }
        }

        visited.erase(crs);
        preMap[crs].clear();

        return true;
    }
};
