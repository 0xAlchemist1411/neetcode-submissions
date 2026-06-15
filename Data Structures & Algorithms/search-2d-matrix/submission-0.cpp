class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<int> vec;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                vec.push_back(matrix[i][j]);
            }
        }

        for(auto& i: vec){
            if(i == target){
                return true;
            }
        }

        return false;
    }
};
