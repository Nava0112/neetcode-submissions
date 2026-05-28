class Solution {
public:
    int findMin(vector<int> &nums) {
        int n=nums.size();
        int l=0, h=n-1;
        int mini=nums[0];
        while(l<h){
            int m=l+(h-l)/2;
            if(nums[m]>nums[h]){
                l=m+1;
            }
            else h=m;
            cout<<nums[m];
        }
        return nums[l+(h-l)/2];
    }
};
