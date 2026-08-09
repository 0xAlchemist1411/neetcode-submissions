class Solution {
public:
    int climbStairs(int n) {
        // Fibonnaci series kinda solution
        int one = 1, two = 1;

        for(int i=0;i<n-1;i++){
            int temp = one;
            one = one + two;
            two = temp; // previous value of one
        }

        return one;
    }
};
