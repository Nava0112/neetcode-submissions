class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        unordered_map<char, int>map;
        for(auto i: t){
            map[i]++;
        }
        int mins = INT_MAX;
        int l = 0;
        pair<int,int> res = {-1, -1};
        int req = t.size();
        for(int r=0; r<n; r++){
            if(map[s[r]]>0) {
                req--; 
            }
            map[s[r]]--;
            cout<<"r"<<r<<endl;
            while(req==0){
                if( res.first == -1 || res.second - res.first > r-l) res = {l,r};
                map[s[l]]++;
                if(map[s[l]]>0){
                    req++;
                }
                cout<<'l'<<l<<endl;
                l++;
                
            }
        }
        if(res.first==-1) return "";
        return s.substr(res.first, res.second - res.first+1);
    }
};

//s.substr(res.first, res.second - res.first)
