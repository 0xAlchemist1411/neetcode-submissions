class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int last = 0;
        priority_queue<int> maxHeap;

        for(auto i: stones){
            maxHeap.push(i);
        }

        while(maxHeap.size() > 1){
            int stone1 = maxHeap.top();
            maxHeap.pop();
            int stone2 = maxHeap.top();
            maxHeap.pop();

            if(stone1 > stone2){
                maxHeap.push(stone1-stone2);
            }
            else if(stone1 < stone2){
                maxHeap.push(stone2-stone1);
            }
            else{
                maxHeap.push(0);
            }
        }

        return maxHeap.top();
    }
};
