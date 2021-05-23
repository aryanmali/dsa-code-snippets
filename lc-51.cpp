//https://leetcode.com/problems/n-queens/

class Solution {
public:
    vector<vector<string>> ans;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n,string(n,'.'));
        ans = {};
        dfs(board,0);
        return ans;
    }
    
    void dfs(vector<string>& board,int row) {
        if(row == board.size()) {
            ans.push_back(board);
            return;
        }   
        for(int col=0;col<board.size();col++) {
            if(isSafe(board,row,col,board.size())) {
                board[row][col] = 'Q';
                dfs(board,row+1);
                board[row][col] = '.';
            }
        }
    }
    
    bool isSafe(vector<string>& board,int row,int col,int n) {
        for (int i = 0; i != row; ++i)
            if (board[i][col] == 'Q')
                return false;
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; --i, --j)
            if (board[i][j] == 'Q')
                return false;
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; --i, ++j)
            if (board[i][j] == 'Q')
                return false;
        return true;
    }
};