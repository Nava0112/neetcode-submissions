class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>visited(n, vector<bool>(m, 0));
        vector<int>dir = {0,-1,0,1,0};
        int cnt=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]=='1' && !visited[i][j]) {
                    q.push({i,j}); cnt++;
                }
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    if(visited[x][y]) continue;
                    visited[x][y]=1;
                    for(int i=0; i<4; i++){
                        int a = x+dir[i];
                        int b = y+dir[i+1];
                        if(a>=0 && a<n && b>=0 && b<m && grid[a][b]=='1' && !visited[a][b]) {
                            q.push({a,b});
                        }
                    }
                }
            }
        }
        return cnt;
    }
};
