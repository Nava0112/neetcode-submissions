class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s2.size();
        unordered_map<char, int>map;
        for(auto i: s1){
            map[i]++;
        }
        int m = s1.size();
        for(int i=0; i<n; i++){
            int j=i;
            unordered_map<char,int>temp(map.begin(), map.end());
            while(j<n && j<i+m){
                if(!temp.count(s2[j])) break;
                temp[s2[j]]--;
                if(temp[s2[j]]==0)temp.erase(s2[j]);
                if(temp.empty()) return true;
                j++;
            }
        }
        return false;
    }
};
