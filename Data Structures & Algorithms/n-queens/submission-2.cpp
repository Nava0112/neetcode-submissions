class Solution {
private:
vector<vector<string>>res;
public:
    bool isValid(int r, int c, int n, vector<string>&board){
        for(int i=0; i<n; i++){
            if(board[i][c]=='Q') return false;
            if(board[r][i]=='Q') return false;
        }
        for(int i=r, j=c; i<n && j<n; i++, j++){
            if(board[i][j]=='Q') return false;
        }
        for(int i=r, j=c; i>=0 && j<n; i--, j++){
            if(board[i][j]=='Q') return false;
        }
        for(int i=r, j=c; i<n && j>=0; i++, j--){
            if(board[i][j]=='Q') return false;
        }
        for(int i=r, j=c; i>=0 && j>=0; i--, j--){
            if(board[i][j]=='Q') return false;
        }
        return true;
    }
    void bt(int row, int n, vector<string>& board){
        if(row == n){
            res.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++){
            if(isValid(row, col, n, board)){
                board[row][col] = 'Q';
                bt(row + 1, n, board);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        bt(0,n,board);
        return res;
    }
};
