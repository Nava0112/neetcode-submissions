class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        unordered_map<int,int>map;
        for(int i=0; i<numbers.size(); i++){
            int val = target-numbers[i];
            if(map.count(val)){
                return {map[val]+1,i+1};
            }
            map[numbers[i]]=i;
        }
        return {};
    }
};
