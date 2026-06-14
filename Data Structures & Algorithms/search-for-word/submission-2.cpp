class Solution {
public:
    bool bt(int i, int j, int k, vector<vector<char>>& board, string word, vector<vector<bool>>valid){
        if(k==word.size()) return true;
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() 
            || board[i][j] != word[k] || valid[i][j]) return false;
        
        if(board[i][j] == word[k]){
            valid[i][j]=1;
            return  bt(i-1,j,k+1,board, word, valid) ||
                bt(i,j-1,k+1,board, word, valid) ||
                bt(i+1,j,k+1,board, word, valid) ||
                bt(i,j+1,k+1,board, word, valid) ;
        }

        
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();
        vector<vector<bool>>valid(n,vector<bool>(m));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]==word[0]){
                    cout<<board[i][j];
                    if(bt(i,j,0,board,word, valid)) return true;
                }
            }
        }
        return false;
    }
};
