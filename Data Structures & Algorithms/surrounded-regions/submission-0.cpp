class Solution {
    int rows, cols;
    vector<pair<int, int>> directions = {
        {1,0}, {-1,0}, {0,1}, {0,-1}
    };

public:
    void capture(vector<vector<char>>& board) {
        queue<pair<int,int>> q;

        // Push all boundary O's
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O' &&
                   (i == 0 || i == rows-1 || j == 0 || j == cols-1)) {

                    q.push({i, j});
                    board[i][j] = 'T';
                }
            }
        }

        while(!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for(auto &dir : directions) {
                int nr = r + dir.first;
                int nc = c + dir.second;

                if(nr >= 0 && nr < rows &&
                   nc >= 0 && nc < cols &&
                   board[nr][nc] == 'O') {

                    board[nr][nc] = 'T';
                    q.push({nr, nc});
                }
            }
        }
    }

    void solve(vector<vector<char>>& board) {
        if(board.empty()) return;

        rows = board.size();
        cols = board[0].size();

        capture(board);

        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
                else if(board[i][j] == 'T')
                    board[i][j] = 'O';
            }
        }
    }
};