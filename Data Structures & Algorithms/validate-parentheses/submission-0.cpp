class Solution {
public:
    bool isValid(string s) {
        stack<int> st;
        unordered_map<char,char>map;
        map['(']=')';
        map['[']=']';
        map['{']='}';
        for(auto c:s){
            if(map.count(c)) st.push(c);
            else {
                if(st.empty()) return false;
                auto top = st.top();
                st.pop();
                if(map[top]!=c) return false;
            }
            
        }
        return st.empty();
    }
};
