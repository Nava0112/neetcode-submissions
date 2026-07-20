class Solution {
public:
    bool func(int a, int b, vector<vector<char>>& board){
        char val = board[a][b];
        for(int i=0; i<9; i++){
            if(i==a) continue;
            if(board[i][b]==val) return false;
        }
        for(int i=0; i<9; i++){
            if(i==b) continue;
            if(board[a][i]==val) return false;
        }
        int x = (a/3)*3;
        int y = (b/3)*3;
        for(int i=x; i<x+3; i++){
            for(int j = y; j<y+3; j++){
                if(i==a && j==b) continue;
                if(board[i][j]==val) return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(board[i][j]=='.') continue;
                if(!func(i, j, board)) return false;
            }
        }
        return true;
    }
};
