class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        queue<int>q;
        vector<int>indegree(n);
        vector<int>ans;
        unordered_map<int,vector<int>>map;
        for(auto a:prerequisites){
            int u=a[0];
            int v=a[1];
            map[v].push_back(u);
            indegree[u]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==0){
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int a=q.front();
            q.pop();
            for(auto k:map[a]){
                indegree[k]--;
                if(indegree[k]==0) {
                    q.push(k);
                    ans.push_back(k);
                }
            }
        }
        for(auto a:indegree){
            if(a!=0) return {};
        }
        return ans;
    }
};
