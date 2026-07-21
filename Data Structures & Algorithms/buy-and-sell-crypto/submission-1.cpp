class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int mini = INT_MAX;
        for(auto i:prices){
            mini = min(mini, i);
            profit = max(profit, i-mini); 
        }
        return profit;
    }
};
