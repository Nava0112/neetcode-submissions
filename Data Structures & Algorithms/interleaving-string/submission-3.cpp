class Solution {
public:
    bool func(int i, int j, int k, string s1, string s2, string s3, vector<vector<int>>&memo){
        if(i>=s1.size()) return memo[i][j]=s2.substr(j, s2.size()-j)==s3.substr(k,s3.size()-k);
        if(j>=s2.size()) return memo[i][j]=s1.substr(i, s1.size()-i)==s3.substr(k,s3.size()-k);
        if(memo[i][j]!=-1) return memo[i][j];
        if(s1[i]==s3[k] && s2[j]==s3[k]) return memo[i][j]=func(i+1,j, k+1, s1, s2, s3, memo) || func(i, j+1, k+1, s1, s2, s3, memo);
        if(s1[i]==s3[k]) return memo[i][j]=func(i+1,j, k+1, s1, s2, s3, memo);
        if(s2[j]==s3[k]) return memo[i][j]=func(i, j+1, k+1, s1, s2, s3, memo);
        return memo[i][j]=false;
    }
    bool isInterleave(string s1, string s2, string s3) {
        if(s1.size() + s2.size() != s3.size()) return false;
        vector<vector<int>>memo(s1.size()+1, vector<int>(s2.size()+1,-1));
        return func(0,0,0,s1,s2,s3, memo);
    }
};
