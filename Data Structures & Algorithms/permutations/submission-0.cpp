class Solution {
private:
vector<vector<int>>ans; 
public:
    void bt(int k, vector<int> &nums, vector<int> &temp , vector<bool> pick){
        if(temp.size()==nums.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<nums.size(); i++){
            if(pick[i]) continue;
            temp.push_back(nums[i]);
            pick[i]=true;
            bt(i+1,nums,temp, pick);
            temp.pop_back();
            pick[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> temp;
        vector<bool> pick(nums.size());
        bt(0,nums,temp,pick);
        return ans;
    }
};
