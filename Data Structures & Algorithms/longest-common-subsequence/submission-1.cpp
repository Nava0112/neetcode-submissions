class Solution {
public:
    int func(int i, int j, string t, string s, vector<vector<int>>&memo){
        if(i<0 || j<0) return 0;
        if(memo[i][j]!=-1) return memo[i][j];
        if(t[i]==s[j]) return memo[i][j]=1+func(i-1, j-1, t, s, memo);
        int dk = func(i-1, j, t, s, memo);
        int sk = func(i, j-1, t, s, memo);
        return memo[i][j]=max(dk,sk);
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n=text1.size();
        int m = text2.size();
        vector<vector<int>>memo(n+1, vector<int>(m+1, -1));
        return func(n-1,m-1,text1,text2, memo);
    }
};
