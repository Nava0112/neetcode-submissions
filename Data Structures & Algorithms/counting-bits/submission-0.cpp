class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>ans(n+1);
        for(int i=0; i<=n; i++){
            ans[i]=(int)__builtin_popcount(i);
        }
        return ans;
    }
};
