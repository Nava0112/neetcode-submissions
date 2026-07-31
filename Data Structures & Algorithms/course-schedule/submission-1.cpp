class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int>indegree(n);
        vector<vector<int>>graph(n);
        queue<int>q;
        for(auto i: prerequisites){
            int u = i[0];
            int v = i[1];
            graph[u].push_back(v);
            indegree[v]++;
        }
        for(int i=0; i<n; i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();
            for(auto i:graph[x]){
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        for(int i=0; i<n; i++){
            if(indegree[i]!=0) return 0;
        }
        return 1;
    }
};
