class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();

        int size = n + m;

        int  i = 0, j = 0;
        int k = 0;

        int idx1 = (size/2)-1;
        int elem1 = -1;

        int idx2 = (size/2);
        int elem2 = -1;

        while(i < n and j < m){
            if(nums1[i] < nums2[j]){
                if(k == idx1){
                    elem1 = nums1[i];
                }
                if(k == idx2){
                    elem2 = nums1[i];
                }
                i++;
                k++;
            }
            else{
                if(k == idx1){
                    elem1 = nums2[j];
                }
                if(k == idx2){
                    elem2 = nums2[j];
                }
                j++;
                k++;
            }
        }

        while(i < n){
            if(k == idx1){  
                elem1 = nums1[i];
            }
            if(k == idx2){
                elem2 = nums1[i];
            }
            i++;
            k++;
        }

        while(j < m){
            if(k == idx1){  
                elem1 = nums2[j];
            }
            if(k == idx2){
                elem2 = nums2[j];
            }
            j++;
            k++;
        }

        if(size%2 == 1){
            return elem2;
        }
        else{
            return (elem1+elem2)/2.0;
        }
    }
};






