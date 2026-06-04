class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        if(nums.size()==1 || nums.size()==0) return -1;
        int slow=0, fast=0;
        while(1){
            slow=nums[slow];
            fast=nums[nums[fast]];
            if(slow==fast){
                int s2=0;
                while(1){
                    if(slow==s2) return slow;
                    slow=nums[slow];
                    s2=nums[s2];
                }
            }
        }
        return -1;
    }
};
