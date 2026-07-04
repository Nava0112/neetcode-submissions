class Solution {
public:
    int func(int i, bool start, vector<vector<int>>&memo, vector<int>&nums){
        if(i==0) if(start) return 0;
        if(i<0) return 0;
        if(memo[i][start]!=-1) return memo[i][start];
        int rob;
        if(i==nums.size()-1) rob = nums[i] + func(i-2, 1, memo, nums);
        else rob = nums[i] + func(i-2, start, memo, nums);
        int skip = func(i-1,start, memo, nums);
        return memo[i][start]=max(rob, skip);
    }
    int rob(vector<int>& nums) {
        int n= nums.size();
        vector<vector<int>>memo(n, vector<int>(2, -1));
        func(n-1, 0, memo,nums);
        return func(n-1, 0, memo,nums);
    }
};
