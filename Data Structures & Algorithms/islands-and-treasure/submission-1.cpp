class Solution {
public:
    void islandsAndTreasure(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,pair<int,int>>>q;
        vector<vector<bool>>visi(n, vector<bool>(m,0));
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j]==0) q.push({0,{i,j}});
            }
        }
        vector<int>dir = {0,-1,0,1,0};
        while(!q.empty()){
            auto top = q.front();
            q.pop();
            int d = top.first;
            auto [x,y] = top.second;
            if(grid[x][y]<d) continue;
            grid[x][y]=d;
            for(int i=0; i<4; i++){
                int a = x + dir[i];
                int b = y + dir[i+1];
                if(a>=0 && a<n && b >=0 && b<m && grid[a][b]>0){
                    q.push({d+1, {a,b}});
                }
            }
        }
    }
};
