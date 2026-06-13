class Solution {
private:
set<vector<int>>ans; 
vector<vector<int>>res; 
public:
    void bt(int k, vector<int>&nums, vector<int>&temp){
        if(k>nums.size()) return;
        vector<int> dum = temp;
        sort(dum.begin(), dum.end());
        ans.insert(dum);
        for(int i=k; i<nums.size(); i++){
            temp.push_back(nums[i]);
            bt(i+1,nums,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>>subsetsWithDup(vector<int>& nums) {
        vector<int> temp;
        bt(0,nums,temp);
        vector<vector<int>>res(ans.begin(),ans.end()); 
        return res;
    }
};
