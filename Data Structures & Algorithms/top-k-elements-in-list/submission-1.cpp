class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i:nums){
            map[i]++;
        }
        vector<pair<int,int>>vec; 
        for(auto it:map){
            vec.push_back({it.second,it.first});
        }
        sort(vec.begin(),vec.end(), greater<pair<int,int>>());
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(vec[i].second);
        }
    return ans;
    }
};
