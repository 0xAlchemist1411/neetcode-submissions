class TimeMap {
    unordered_map<string,vector<pair<string,int>>> timeMap;
public:
    TimeMap() {}
    
    void set(string key, string value, int timestamp) {
        timeMap[key].push_back({value, timestamp});
    }
    
    string get(string key, int timestamp) {
        if (timeMap.find(key) == timeMap.end()) { // if found nothing
            return "";
        }

        auto arr = timeMap[key];
        string ans = "";

        for(auto &it: arr){
            if(it.second <= timestamp){ // recent timestamp
                ans = it.first;
            }
        }
            
        return ans;
    }
};
