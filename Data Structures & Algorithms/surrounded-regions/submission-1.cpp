class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();
        queue<pair<int,int>>q;
        vector<int> dir = {0,-1,0,1,0};
        vector<vector<bool>>visi(n, vector<bool>(m, 0));
        for(int i=0; i<n; i++){
            if(board[i][0]=='O') q.push({i,0});
        }
        for(int i=0; i<n; i++){
            if(board[i][m-1]=='O') q.push({i,m-1});
        }
        for(int j=1; j<m-1; j++){
            if(board[0][j]=='O') q.push({0,j});
        }
        for(int j = 1; j <m-1; j++){
            if(board[n-1][j]=='O') q.push({n-1,j});
        }
        while(!q.empty()){
            auto [x,y] = q.front();
            q.pop();
            if(visi[x][y]) continue;
            visi[x][y]=1;
            for(int i=0; i<4; i++){
                int a = x + dir[i];
                int b = y + dir[i+1];
                if(a>=0 && a<n && b>=0 && b<m && !visi[a][b] && board[a][b]=='O'){
                    q.push({a,b});
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(board[i][j]=='O'){
                    if(!visi[i][j]) board[i][j]='X';
                }
            }
        }
    }
};
