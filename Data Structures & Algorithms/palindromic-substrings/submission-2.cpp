class Solution {
public:
    int func(int i, int j, string s){
        int cnt =0;
        while(i>=0 && j<s.size() && i<=j && s[i]==s[j]){
            cnt++;
            i--;
            j++;
        }
        return cnt;
    }
    int countSubstrings(string s) {
        int ans = 1;
        int n=s.size();
        for(int i=0; i<n-1; i++){
            ans+=func(i,i,s);
            ans+=func(i,i+1,s);
        }
        return ans;
    }
};
