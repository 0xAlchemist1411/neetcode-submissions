class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> arr;

        for(auto i: nums1){
            arr.push_back(i);
        }

        for(auto i: nums2){
            arr.push_back(i);
        }

        sort(arr.begin(), arr.end());
        int n = arr.size();
        double mid;
        if(n % 2 == 0){
            mid = (arr[n/2 - 1] + arr[n/2])/2.0;
        }
        else{
            mid = arr[n/2];
        }

        return mid;
    }
};
