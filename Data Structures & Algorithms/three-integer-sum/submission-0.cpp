class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n=nums.size();
        int tar=0;
        vector<vector<int>>ans; 
        sort(nums.begin(),nums.end());
        for(int i=0; i<n; i++){
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            int j=i+1;
            int k=n-1;
            while(i<j && j<k){
                int val=nums[i]+nums[j]+nums[k];
                if(val==tar) {
                    ans.push_back({nums[i],nums[j],nums[k]});
                    j++;
                    k--;
                    while (j < k && nums[j] == nums[j - 1])
                        j++;

                    while (j < k && nums[k] == nums[k + 1])
                        k--;
                }
                if(val<tar)j++;
                if(val>tar)k--;
            }
        }
        return ans;
    }
};
