class Solution {
    int directions[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
public:
    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        int res = 0;

        for (int r = 0; r < row; r++) {
            for (int c = 0; c < col; c++) {
                if (grid[r][c] == '1') {
                    dfs(grid, r, c);
                    res++;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<char>>& grid, int row, int col){
        if(row < 0 or col < 0 or row >= grid.size() or col >= grid[0].size() or grid[row][col] == '0'){
            return;
        }

        grid[row][col] = '0';
        for(int i=0;i<4;i++){
            dfs(grid, row + directions[i][0], col + directions[i][1]);
        }
    }
};













