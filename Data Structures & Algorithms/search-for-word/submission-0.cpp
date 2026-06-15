class Solution {
public:
    bool dfs(int idx, int row, int col, vector<vector<char>>& board, string &word){
        if(idx == word.size()) {
            return true;
        }

        if(row < 0 || col < 0 || row >= board.size() || col >= board[0].size() || board[row][col] != word[idx]){
            return false;
        }

        // Mark current cell as visited
        char temp = board[row][col];
        board[row][col] = '#';

        // Explore all 4 directions
        bool found =
            dfs(idx + 1, row + 1, col, board, word) ||
            dfs(idx + 1, row - 1, col, board, word) ||
            dfs(idx + 1, row, col + 1, board, word) ||
            dfs(idx + 1, row, col - 1, board, word);
        
        board[row][col] = temp;


        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(dfs(0, i, j, board, word)){
                    return true;
                }
            }
        }

        return false;
    }
};
