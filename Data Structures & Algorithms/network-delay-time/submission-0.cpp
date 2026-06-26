class Solution {
public:
    typedef pair<int,int> node;
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<vector<int>>>graph;
        priority_queue<node,vector<node>,greater<node>>pq;
        for(auto &a:times){
            int u = a[0];
            int v = a[1];
            int t = a[2];
            graph[u].push_back({v,t});
        }
        vector<int>dis(n+1,INT_MAX);
        dis[k]=0;
        pq.push({0,k});
        while(!pq.empty()){
            auto [t,v] = pq.top();
            pq.pop();
            if(t>dis[v]) continue;
            dis[v]=t;
            cout<<v<<" "<<dis[v]<<endl;
            for(auto &a : graph[v]){
                int next = a[0];
                int wt = a[1];
                if(dis[next] > t + wt){
                    dis[next] = t + wt;
                    pq.push({dis[next], next});
                }
            }
        }
        int sum =0;
        for(int i=1; i<=n; i++){
            if(dis[i]==INT_MAX) return -1;
            sum = max(sum,dis[i]);
        }
        return sum;
    }
};
