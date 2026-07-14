class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int mxt=INT_MIN;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                int temp =0;
                for(int k = i; k<=j; k++){
                    temp+=nums[k];
                }
                mxt=max(mxt, temp);
            }
        }
        return mxt;
    }
};
