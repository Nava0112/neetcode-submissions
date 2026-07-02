class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(n+1);
        for(int i=2; i<=n; i++){
            int one = cost[i-1]+dp[i-1];
            int two = cost[i-2]+dp[i-2];
            dp[i]=min(one,two);
        }
        return dp[n];
    }
};
