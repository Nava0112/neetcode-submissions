class Solution {
private:
    int totsum;

    int func(int k, int curr, int target,
             vector<int>& nums,
             vector<vector<int>>& memo)
    {
        if (k == nums.size())
            return curr == target;
        if (memo[k][curr + totsum] != -1)
            return memo[k][curr + totsum];
        int plus = func(k + 1, curr + nums[k], target, nums, memo);
        int minus = func(k + 1, curr - nums[k], target, nums, memo);
        return memo[k][curr + totsum] = plus + minus;
    }

public:
    int findTargetSumWays(vector<int>& nums, int target) {
        totsum = accumulate(nums.begin(), nums.end(), 0);
        if (abs(target) > totsum) return 0;
        vector<vector<int>> memo(nums.size(),vector<int>(2 * totsum + 1, -1));
        return func(0, 0, target, nums, memo);
    }
};