class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>valid(n, vector<bool>(m));
        queue<pair<int,pair<int,int>>>q;
        vector<int>dir={0,1,0,-1,0};
        int count=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) {
                    q.push({0,{i,j}}); 
                    count=0;
                }
                while(!q.empty()){
                    auto [dis, pos] = q.front();
                    auto [x, y] = pos;
                    q.pop();
                    if(dis > grid[x][y]) continue;
                    if(grid[x][y]!=0){
                        grid[x][y]=dis;
                    }
                    for(int i=0; i<4; i++){
                        int a=x+dir[i];
                        int b=y+dir[i+1];
                        if(a>=0 && b>=0 && a<n && b<m && grid[a][b]>0){
                            q.push({dis+1,{a,b}});
                        }
                    }
                }
            }
        }
    }
};
