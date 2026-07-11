class Solution {
private:
vector<int>dir={0,1,0,-1,0};
public:
    int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& memo){
        if(i>=matrix.size() || j>=matrix[0].size() || i<0 || j<0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        int ans = 1;
        for(int a=0; a<4; a++){
            int x = i+dir[a];
            int y = j+dir[a+1];
            if(x<matrix.size() && y<matrix[0].size() && x>=0 && y>=0 && matrix[x][y]>matrix[i][j]) ans = max(ans, 1 + func(x,y,matrix, memo));
        }
        return memo[i][j]=ans;
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n= matrix.size();
        int m = matrix[0].size();
        int ans = 1;
        vector<vector<int>>memo(n+1, vector<int>(m+1,-1));
        for(int i=0; i<n; i++){
            for(int j=0; j<m ; j++){
                ans = max(ans, func(i,j,matrix, memo));
            }
        }
        return ans;
    }
};
