class Solution {
private:
vector<vector<int>>ans; 
public:
    void bt(int k, vector<int>&nums, vector<int>&temp){
        if(k>nums.size()) return;
        ans.push_back(temp);
        for(int i=k; i<nums.size(); i++){
            temp.push_back(nums[i]);
            bt(i+1,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>>subsets(vector<int>& nums) {
        vector<int> temp;
        bt(0,nums,temp);
        return ans;
    }
};
