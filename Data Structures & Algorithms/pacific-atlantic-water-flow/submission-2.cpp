class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<bool>>pacific(n,vector<bool> (m));
        vector<vector<bool>>atlantic(n,vector<bool> (m));
        queue<pair<int,pair<int,int>>>q;
        vector<int>dir={0,-1,0,1,0};
        for(int i=0; i<n; i++){
            q.push({heights[i][0],{i,0}});
        }
        for(int j=1; j<m; j++){
            q.push({heights[0][j],{0,j}});
        }
        while(!q.empty()){
            auto [d,cor] = q.front(); q.pop();
            auto [x,y] = cor;
            if(pacific[x][y]) continue;
            pacific[x][y]=1;
            for(int i=0; i<4; i++){
                int a = x + dir[i];
                int b = y + dir[i+1];
                if(a>=0 && a<n && b>=0 && b<m && !pacific[a][b] && heights[a][b]>=d){
                    q.push({heights[a][b],{a,b}});
                }
            }
        }
        for(int i=0; i<n; i++){
            q.push({heights[i][m-1],{i,m-1}});
        }
        for(int j=0; j<m-1; j++){
            q.push({heights[n-1][j],{n-1,j}});
        }

        while(!q.empty()){
            auto [d,cor] = q.front(); q.pop();
            auto [x,y] = cor;
            if(atlantic[x][y]) continue;
            atlantic[x][y]=1;
            for(int i=0; i<4; i++){
                int a = x + dir[i];
                int b = y + dir[i+1];
                if(a>=0 && a<n && b>=0 && b<m && !atlantic[a][b] && heights[a][b]>=d){
                    q.push({heights[a][b],{a,b}});
                }
            }
        }
        vector<vector<int>>ans;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(atlantic[i][j] && pacific[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
};
