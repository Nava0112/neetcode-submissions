class Solution {
public:
    int ans = 1001;
    int a;
    void func(int k, string &s, unordered_map<char,int>map){
        int count=0;
        int i=k;
        while(i<s.size()){
            count++;
            if(map.count(s[i])){
                map[s[i]]--;
                if(map[s[i]]==0) map.erase(s[i]);
            }

            if(map.empty()){
                if(count<ans){
                    ans=count;
                    a=k;
                }
            }
            
            i++;
        }
    }
    string minWindow(string s, string t) {
        if(s.size()<t.size()) return "";
        unordered_map<char,int>map;
        for(auto c:t){
            map[c]++;
        }
        for(int i=0; i<s.size(); i++){
            if(map.count(s[i])){
                func(i,s,map);
            }
        }
        if(ans==1001) return "";
        return s.substr(a,ans);
    }
};
