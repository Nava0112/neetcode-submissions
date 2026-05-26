class Solution {
public:
    bool isValid(int a, int b, vector<vector<char>>& board){
        char k=board[a][b];
        for(int i=0; i<9; i++){
            if(a==i) continue;
            cout<<"v"<<" ";
            if(k==board[i][b]) return false;
        }
        for(int i=0; i<9; i++){
            if(b==i) continue;
            cout<<"h"<<" ";
            if(k==board[a][i]) return false;
        }
        int x=a/3;
        x=x*3;
        int y=b/3;
        y=y*3;
        for(int i=x; i<x+3; i++){
            for(int j=y; j<y+3; j++){
                if(a==i && b==j) continue;
                cout<<"d"<<" ";
                if(board[i][j]==k) return false;
            }
        }
        return 1;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int i=0; i<9; i++){
            for(int j=0; j<9; j++){
                if(!isdigit(board[i][j])) continue;
                if(!isValid(i,j, board)) return 0;
            }
        }
        return 1;
    }
};
