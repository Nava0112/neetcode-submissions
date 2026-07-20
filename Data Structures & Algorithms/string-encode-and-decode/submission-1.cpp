class Solution {
public:

    string encode(vector<string>& strs) {
        string ans;
        for(auto s:strs){
            ans+=s;
            ans+='-';
        }
        return ans;
    }

    vector<string> decode(string s) {
        vector<string>ans;
        int j=0;
        for(int i=0;i <s.size(); i++){
            if(s[i]=='-'){
                ans.push_back(s.substr(j, i-j));
                j=i+1;
            }
        }
        return ans;
    }
};
