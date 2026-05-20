class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        if(n==0 || n==1) return n;
        unordered_set<int>set(nums.begin(),nums.end());
        int longest=1;
        for(auto k:set){
            if(set.count(k-1)){
                int curr = k;
                int len=1;
                while(set.count(curr+1)){
                    curr++;
                    len++;
                }
                longest=max(longest,len+1);
            }
        }
        return longest;
    }
};
