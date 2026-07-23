class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int>map;
        for(auto i: t){
            map[i]++;
        }
        int mins = INT_MAX;
        string ans = "";
        for(int i=0; i<n; i++){
            if(map.count(s[i])){
                int j=i;
                unordered_map<char, int>temp(map.begin(), map.end());
                while(j<n){
                    cout<<s[j]<<endl;
                    if(temp.count(s[j])) temp[s[j]]--;
                    if(temp[s[j]]==0) temp.erase(s[j]);
                    if(temp.empty()){
                        if(mins>j-i+1){
                            mins=j-i+1;
                            ans = s.substr(i, j-i+1);
                        }
                        break;
                    }
                    j++;
                }
            }
        }
        return ans;
    }
};
