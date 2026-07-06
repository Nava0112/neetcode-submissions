class Solution {
public:
    int func( int curr, vector<int>& coins, int amount, vector<int>&memo){
        if(curr>amount) return INT_MAX;
        if(curr==amount) return 0;
        if(memo[curr]!=-1) return memo[curr];
        int ans=INT_MAX;
        for (int coin : coins) {
            if(coin==INT_MAX) continue;
            int temp = func(curr + coin, coins, amount, memo);

            if (temp != INT_MAX)
                ans = min(ans, temp + 1);
        }
        return memo[curr]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int>memo(amount+1,-1);
        int ans = func(0,coins,amount, memo);
        return (ans==INT_MAX)?-1:ans;
    }
};
