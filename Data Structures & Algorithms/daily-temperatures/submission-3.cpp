class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        stack<int>st;
        vector<int> ans(n);
        for(int i=0; i<n; i++){
            while(!st.empty() && temperatures[st.top()] < temperatures[i]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        for(int i=0; i<n-1; i++){
            if(ans[i]==0) continue;
            ans [i] = ans[i]-i;
        }
        return ans;
    }
};
