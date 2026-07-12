class Solution {
public:
    int func(int i, string s, vector<int>&memo){
        if(i==s.size()) return memo[i]=1;
        if(memo[i]!=-1) return memo[i];
        if(s[i]=='0') return memo[i]=0;
        int ans = func(i+1, s, memo);
        if(i+1<s.size() &&  (s[i]=='1' || s[i]=='2' && s[i+1]<'7')) ans += func(i+2,s, memo);
        return memo[i]=ans;
    }
    int numDecodings(string s) {
        vector<int>memo(s.size()+1, -1);
        return func(0, s, memo);
    }
};
