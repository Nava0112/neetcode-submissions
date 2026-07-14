class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mxt=INT_MIN;
        for(int i=0; i<n; i++){
            int temp =0;
            for(int j=i; j<n; j++){
                temp += nums[j];
                mxt=max(mxt, temp);
            }
        }
        return mxt;
    }
};
