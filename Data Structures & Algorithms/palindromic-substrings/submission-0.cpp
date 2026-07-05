class Solution {
public:
    bool ispal(string s) {
        int i=0; 
        int j=s.size() -1;
        while(i<j){
            while(i<j && !isalnum(s[i])) i++;
            while(j>i && !isalnum(s[j])) j--;
            if(tolower(s[i])==tolower(s[j])){
                i++;
                j--;
            }
            else return false;
        }
        return true;
    }
    int countSubstrings(string s) {
        int n=s.size();
        int cnt = 0;
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                string str = s.substr(i,j-i+1);
                if(ispal(str)) cnt++;
            }
        }
        return cnt;
    }
};
