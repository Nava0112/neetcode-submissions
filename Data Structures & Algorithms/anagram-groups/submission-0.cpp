class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        unordered_map<string,vector<int>>map;
        for(int i=0; i<n; i++){
            string s=strs[i];
            sort(s.begin(),s.end());
            map[s].emplace_back(i);
        }
        vector<vector<string>> ans;
        for(auto it:map){
            vector<string>temp;
            vector<int> dum=it.second;
            for(int i=0; i<dum.size(); i++){
                temp.emplace_back(strs[dum[i]]);
            }
            ans.emplace_back(temp);
        }
        return ans;
    }
};
