class Solution {
private:
vector<vector<int>>ans; 
public:
    void bt(int k, vector<int>&nums, vector<int> &temp, int sum, int target){
        if(k>nums.size() || sum>target) return;
        if(sum==target) {
            ans.push_back(temp);
            return;
        }
        for(int i=k; i<nums.size(); i++){
            if(i>k && nums[i]==nums[i-1]) continue;
            temp.push_back(nums[i]);
            bt(i+1,nums,temp,sum+nums[i], target);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& nums, int target) {
        vector<int> temp;
        sort(nums.begin(),nums.end());
        bt(0,nums,temp,0,target);
        return ans;
    }
};
