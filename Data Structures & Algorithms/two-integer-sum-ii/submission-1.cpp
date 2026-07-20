class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l=0;
        int h = numbers.size()-1;
        while(l<h){
            int val = numbers[l] + numbers[h];
            if(val == target) return {l+1, h+1};
            if(val > target) h--;
            if(val < target) l++;
        }
        return {};
    }
};
