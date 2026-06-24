class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>graph;
        for(auto a:edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        vector<bool>visi(n);
        queue<int>q;
        int count=0;
        for(auto i:graph){
            if(visi[i.first]) continue;
            count++;
            q.push(i.first);
            while(!q.empty()){
                int k = q.front();
                q.pop();
                if(visi[k]) continue;
                visi[k]=1;
                for(auto a:graph[k]){
                    q.push(a);
                }
            }
        }
        for(auto a:visi){
            if(a!=1) count++;
        }
        return count;
    }
};
