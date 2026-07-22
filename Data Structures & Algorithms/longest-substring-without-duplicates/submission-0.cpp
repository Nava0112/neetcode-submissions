class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        int i=0; 
        int j=0;
        int ans =0;
        int cnt=0;
        unordered_set<char>st;
        while(j<n){
            while(st.count(s[j])){
                st.erase(s[i]);
                i++;
            }
            st.insert(s[j]);
            j++;
            ans=max(ans,j-i);
        }
        return ans;
    }
};
