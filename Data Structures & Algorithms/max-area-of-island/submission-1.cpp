class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        int maxArea = 0;

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                // if(grid[i][j] == 1) {
                    maxArea = max(maxArea, dfs(i, j, grid));
                // }
            }
        }

        return maxArea;
    }

    int dfs(int row, int col, vector<vector<int>>& grid){
        if(row < 0 || row >= grid.size() || col < 0 || col >= grid[0].size() || grid[row][col] == 0){
            return 0;
        }

        grid[row][col] = 0;

        int area = 1;

        for(int i = 0; i < 4; i++) {
            area += dfs(row + directions[i][0], col + directions[i][1], grid);
        }

        return area;
    }
};
