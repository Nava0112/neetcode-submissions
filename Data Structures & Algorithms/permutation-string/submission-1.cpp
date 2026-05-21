class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char,int>map;
        for(char c:s1){
            map[c]++;
        }
        for(int i=0; i<s2.size(); i++){
            if(map.count(s2[i])){
                cout<<s2[i];
                int j=i;
                unordered_map<char,int>mp(map.begin(),map.end());
                while(mp.count(s2[j])){
                    cout<<s2[j];
                    mp[s2[j]]--;
                    if(mp[s2[j]]==0) mp.erase(s2[j]);
                    if(mp.empty()) return true;
                    j++;
                }
            }
        }
        return false;
    }
};
