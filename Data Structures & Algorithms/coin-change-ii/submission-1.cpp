class Solution {
public:
    int func(int k, int curr, int amount, vector<int>& coins, vector<vector<int>>&memo){
        if(curr==amount) return 1;
        if(curr>amount) return 0;
        if(k == coins.size()) return 0;
        if(memo[k][curr]!=-1) return memo[k][curr];
        int ans=0;
        for(int i=k; i<coins.size(); i++){
            ans += func(i, curr+coins[i], amount, coins, memo);
        }
        return memo[k][curr]=ans;
    }
    int change(int amount, vector<int>& coins) {
        vector<vector<int>>memo(coins.size(), vector<int>(amount, -1));
        return func(0, 0,amount,coins, memo);
    }
};
