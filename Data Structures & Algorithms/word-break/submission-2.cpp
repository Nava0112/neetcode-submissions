class Solution {
public:
    bool func(int i, string s, vector<string>& wordDict, vector<int>&memo){
        if(i==s.size()) return true;
        if(memo[i]!=-1) return memo[i];
        bool flag = false;
        for(auto str:wordDict){
            int k = str.size();
            if(s.substr(i,k)==str) {
                flag = func(i+k, s, wordDict, memo);
            }
            if(flag) return memo[i]=true;
            else continue;
        }
        return memo[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<int>memo(s.size()+1,-1);
        return func(0, s,wordDict, memo);
    }
};
