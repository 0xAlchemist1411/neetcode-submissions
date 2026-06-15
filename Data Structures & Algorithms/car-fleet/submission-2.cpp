class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        vector<pair<int,int>> pair;
        for(int i=0;i<position.size();i++){
            pair.push_back({position[i],speed[i]});
        }

        sort(pair.begin(),pair.end());

        vector<double> fleets;

        for(int i=pair.size()-1;i >= 0;i--){
            fleets.push_back((double)(target - pair[i].first) / pair[i].second); // inserting time to reach always
            if(fleets.size() >= 2 and fleets.back() <= fleets[fleets.size() - 2]){ // to compare last and 2nd last element
                fleets.pop_back();
            }
        } 

        return fleets.size();
    }
};
