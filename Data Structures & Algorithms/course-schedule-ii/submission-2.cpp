class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indegree(n);
        vector<vector<int>>graph(n);
        queue<int>q;
        vector<int> ans;
        for(auto i: prerequisites){
            int u = i[0];
            int v = i[1];
            graph[v].push_back(u);
            indegree[u]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==0) {
                q.push(i);
                ans.push_back(i);
            }
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i:graph[x]){
                indegree[i]--;
                if(indegree[i]==0) {
                    q.push(i);
                    ans.push_back(i);
                }
            }
        }
        if(ans.size() != n) return {};
        return ans;
    }
};
