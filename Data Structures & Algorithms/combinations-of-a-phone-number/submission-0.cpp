class Solution {
private:
unordered_map<char, vector<char>> mp = {
    {'2', {'a', 'b', 'c'}},
    {'3', {'d', 'e', 'f'}},
    {'4', {'g', 'h', 'i'}},
    {'5', {'j', 'k', 'l'}},
    {'6', {'m', 'n', 'o'}},
    {'7', {'p', 'q', 'r', 's'}},
    {'8', {'t', 'u', 'v'}},
    {'9', {'w', 'x', 'y', 'z'}}
};
vector<string>ans;
public:
    void bt(int k, string d, string temp){
        if(temp.size()==d.size()){
            ans.push_back(temp);
            return;
        }
        for(int i=0; i<mp[d[k]].size(); i++){
            temp+=mp[d[k]][i];
            bt(k+1, d, temp);
            temp.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        if(digits.empty()) return {};
        bt(0,digits,"");
        return ans;
    }
};
