class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int>st;
        vector<int>left(n,-1);
        vector<int>right(n, n);
        for(int i=0; i<n; i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                right[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--){
            while(!st.empty() && heights[st.top()]>heights[i]){
                left[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        int ans=0;
        for(int i=0; i<n; i++){
            int temp = heights[i]*(right[i]-left[i]-1);
            if(ans<temp){
                ans=temp;
                cout<<i<<" "<<temp<<endl;
            }
        }
        return ans;
    }
};
