class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        stack<int>right;
        stack<int>left;
        vector<int> l(n,-1);
        vector<int> r(n,n);
        int sum=0;
        for(int i=0; i<n; i++){
            while(!right.empty() && heights[right.top()]>heights[i]){
                r[right.top()]=i;
                right.pop();
            }
            right.push(i);
        }
        for(int i=n-1; i>=0; i--){
            while(!left.empty() && heights[left.top()]>heights[i]){
                l[left.top()]=i;
                left.pop();
            }
            left.push(i);
        }
        for(int i=0; i<n; i++){
            cout<<l[i]<<" ";
        }
        cout<<"\n";
        for(int i=0; i<n; i++){
            cout<<r[i]<<" ";
        }
        cout<<"\n";
        for(int i=0; i<n; i++){
            int val=(r[i]-l[i]-1)*heights[i];
            cout<<val<< " ";
            sum=max(sum,val);
        }
        return sum;
    }
};
