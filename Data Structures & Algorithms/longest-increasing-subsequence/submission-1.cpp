class Solution {
public:
    int func(int i, int j, vector<int>&nums, vector<int>&memo){
        if(i==nums.size() || j==nums.size()) return 0;
        if(memo[i]!=-1) return memo[i];
        int take = (nums[j]>nums[i])?func(j, j+1, nums, memo)+1:0;
        int dt = func(i, j+1, nums, memo);
        return memo[i]=max(take,dt);
    }
    int lengthOfLIS(vector<int>& nums) {
        int maxel = 0;
        vector<int>memo(nums.size(),-1);
        for(int i=0; i<nums.size(); i++){
            maxel = max(maxel, 1+func(i,i,nums, memo));
        }
        return maxel;
    }
};
