class Solution {
public:
    int func(int i, bool b, vector<int>&prices, vector<vector<int>>&memo){
        if(i>=prices.size()) return 0;
        if(memo[i][b]!=-1) return memo[i][b];
        int sell , buy, skip;
        if(b){
            sell = func(i+2, 0, prices, memo)+prices[i];
            skip = func(i+1, 1, prices, memo);
            return memo[i][b]=max(sell,skip);
        }
        else{
            skip =  func(i+1, 0, prices, memo);
            buy = func(i+1, 1, prices, memo) - prices[i];
            if(b) return memo[i][b]=skip;
            return memo[i][b]=max(buy, skip);
        }
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>>memo(n+1,vector<int>(2,-1));
        return func(0,0,prices, memo);
    }
};
