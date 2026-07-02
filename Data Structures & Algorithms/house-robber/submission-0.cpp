class Solution {
public:
    int func(int i, vector<int>&memo, vector<int>&nums){
        if(i<0) return 0;
        if(memo[i]!=-1) return memo[i];
        int rob = nums[i] + func(i-2, memo, nums);
        int skip = func(i-1, memo, nums);
        return memo[i]=max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<int>memo(n, -1);
        func(n-1,memo,nums);
        return memo[n-1];
    }
};
