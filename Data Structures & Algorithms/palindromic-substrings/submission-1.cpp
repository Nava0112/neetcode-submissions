class Solution {
public:
    int ispal(int a, int b, string s, vector<vector<int>>&memo) {
        int i=a, j=b;
        while(i<j){
            if(memo[i][j]==1) return memo[a][b]=true;
            while(i<j && !isalnum(s[i])) i++;
            while(j>i && !isalnum(s[j])) j--;
            if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }
            else return memo[i][j] = 0;
        }
        return memo[a][b]=1;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt = 0;
        vector<vector<int>>memo(n, vector<int>(n,-1));
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(ispal(i, j, s, memo)) cnt++;
            }
        }
        return cnt;
    }
};
