class Solution {
public:
    typedef pair<float,vector<int>> node;
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        int n = points.size();
        priority_queue<node,vector<node>,greater<node>>pq;
        for(auto x:points){
            int a=x[0];
            int b=x[1];
            float dis = sqrt(a*a + b*b);
            pq.push({dis,x});
        }
        vector<vector<int> >ans;
        for(int i=0; i<k; i++){
            ans.push_back(pq.top().second);
            pq.pop();
        } 
        return ans;
    }
};
