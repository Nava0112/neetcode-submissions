class Solution {
public:
    bool isPalindrome(string s) {
        string str = "";
        for(char c:s){
            c=tolower(c);
            if(isalnum(c)){
                str+=c;
            }
        }
        string ans=str;
        reverse(ans.begin(),ans.end());
        cout<<ans<<" "<<str;
        return (str==ans)?1:0;
    }
};
