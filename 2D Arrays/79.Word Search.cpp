class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows = board.size(); 
        int cols = board[0].size();
        for(int i = 0; i < rows; i++) {
            for(int j = 0; j < cols; j++) {
                if(board[i][j] == word[0] && search(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }

    bool search(vector<vector<char>>& board, string word, int i, int j, int idx) {
        if(idx == word.size()) {
            return true;
        }
        if(i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[idx]) {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '*';
        bool ans = search(board, word, i - 1, j, idx + 1) ||
                   search(board, word, i + 1, j, idx + 1) ||
                   search(board, word, i, j - 1, idx + 1) ||
                   search(board, word, i, j + 1, idx + 1);
        board[i][j] = temp;
        return ans;
    }
};
