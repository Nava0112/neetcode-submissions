class Solution {
public:
    bool isValid(string s) {
        unordered_map<char,char>map = {
            {'}', '{'},
            {']', '['},
            {')', '('}
        };
        stack<char>st;
        for(auto i:s){
            if(map.count(i)){
                if(st.empty()) return 0;
                if(st.top()!=map[i]) return false;
                st.pop();
            }
            else st.push(i);
        }
        if(st.empty()) return 1;
        return 0;
    }
};
