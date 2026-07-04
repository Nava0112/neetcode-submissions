class Solution {
public:
    string pal(int i, int j, string s){
        while(i >= 0 && j < s.size() && s[i] == s[j]){
            i--;
            j++;
        }
        return s.substr(i + 1, j - i - 1);
    }
    string longestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        string ans = "";
        for(int i=0; i<s.size()-1; i++){
            if(pal(i,i,s).size()>ans.size()) {
                ans=pal(i,i,s);
            }
            if(s[i]==s[i+1]){
                if(pal(i,i+1,s).size()>ans.size()) {
                    ans=pal(i,i+1,s);
                }
            }
        }
        return ans;
    }
};
