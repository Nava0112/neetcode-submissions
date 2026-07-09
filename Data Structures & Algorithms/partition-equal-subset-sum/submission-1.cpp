class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int tot = accumulate(nums.begin(), nums.end(), 0);
        if(tot%2==1) return false;
        vector<vector<int>> memo(nums.size(), vector<int>(tot + 1, -1));
        return func(nums.size()-1, 0, tot/2, nums, memo);
    }
private:
    bool func(int i, int sum, int tot, vector<int>&nums, vector<vector<int>>&memo){
        if(i<0 && sum==tot) return 1;
        if(sum>tot) return 0;
        if(sum==tot) return memo[i][sum]=1;
        if (i < 0) return sum == tot;
        if(memo[i][sum]!=-1) return memo[i][sum];
        int t=func(i-1, sum+nums[i], tot, nums, memo);
        int d=func(i-1, sum, tot, nums, memo);
        return memo[i][sum] = t || d;
    }
};
