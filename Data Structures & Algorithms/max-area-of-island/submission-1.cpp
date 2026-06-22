class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n= grid.size();
        int m=grid[0].size();
        vector<vector<bool>>valid(n, vector<bool>(m));
        queue<pair<int,int>>q;
        vector<int>dir={0,1,0,-1,0};
        int count=0;
        int maxArea=0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(valid[i][j]) continue;
                if(grid[i][j]==1) {
                    q.push({i,j}); 
                    valid[i][j]=1;
                    count=0;
                    while(!q.empty()){
                        auto [x,y] = q.front();
                        q.pop();
                        count++;
                        maxArea=max(maxArea,count);
                        for(int i=0; i<4; i++){
                            int a=x+dir[i];
                            int b=y+dir[i+1];
                            if(a>=0 && b>=0 && a<n && b<m && grid[a][b]==1 && !valid[a][b]){
                                q.push({a,b});
                                valid[a][b]=1;
                            }
                        }
                    }
                }
            }
        }
        return maxArea;
    }
};
