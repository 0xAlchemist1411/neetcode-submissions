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

        auto &arr = timeMap[key];
        string ans = "";

        int l = 0, r = arr.size()-1;

        while(l <= r){
            int mid = l + (r-l)/2;
            if(arr[mid].second <= timestamp){
                ans = arr[mid].first; // valid ans
                l = mid + 1; 
            }
            else{
                r = mid - 1;
            }
        }
            
        return ans;
    }
};
