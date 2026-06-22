class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>valid(n, vector<bool>(m));
        queue<pair<int,int>>q;
        vector<int>dir={0,1,0,-1,0};
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(valid[i][j]) continue;
                if(grid[i][j]=='1') {
                    q.push({i,j}); 
                    count++;
                }
                while(!q.empty()){
                    auto [x,y] = q.front();
                    q.pop();
                    cout<<x<<" "<<y<<endl;
                    for(int i=0; i<4; i++){
                        int a=x+dir[i];
                        int b=y+dir[i+1];
                        if(a>=0 && b>=0 && a<n && b<m && grid[a][b]=='1' && !valid[a][b]){
                            q.push({a,b});
                            valid[a][b]=1;
                        }
                    }
                }
            }
        }
        return count;
    }
};
