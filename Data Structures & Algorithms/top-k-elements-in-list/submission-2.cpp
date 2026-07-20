class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>map;
        for(int i:nums){
            map[i]++;
        }
        priority_queue<pair<int,int>>pq;
        for(auto i:map){
            pq.push({i.second, i.first});
        }
        vector<int>ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
