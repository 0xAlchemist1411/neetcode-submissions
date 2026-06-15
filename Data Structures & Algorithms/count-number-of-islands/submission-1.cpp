class Solution {
public:
    void dfs(int row,int col,vector<vector<int>> &vis,vector<vector<char>> &grid,int n,int m){
        vis[row][col] = 1;
        //Traverse the neigbours and mark them if its a land
        for(int delrow=-1;delrow<=1;delrow++){//4-ways for traversing neigbours
            int nrow = row + delrow;
            int ncol = col;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,vis,grid,n,m);
            }
        }
        for(int delcol=-1;delcol<=1;delcol++){//another 4-ways for traversing neigbours
            int nrow = row;
            int ncol = col + delcol;
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m 
            && !vis[nrow][ncol] && grid[nrow][ncol]=='1'){
                dfs(nrow,ncol,vis,grid,n,m);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        int cnt = 0;//counter to count no. of islands
        for(int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!vis[row][col] and grid[row][col]=='1'){
                    cnt++;
                    dfs(row,col,vis,grid,n,m);
                }
            }
        }

        return cnt;
    }
};
