class Solution {
private:
vector<string>ans;
public:
    void bt(int o, int c, int n, string s){
        if(o==n && c==n){
            ans.push_back(s);
            return;
        }
        if(o<n) bt(o+1,c,n,s+'(');
        if(c<o) bt(o,c+1,n,s+')');
    }
    vector<string> generateParenthesis(int n) {
        bt(0,0,n,"");
        return ans;
    }
};
