class Solution {
private:
    unordered_map<int,vector<int>>graph;
public:
    bool dfs(int node, int parent, vector<bool>&visit){
        for(auto &a:graph[node]){
            if(a==parent) continue;
            if(visit[a]) return true;
            visit[a]=1;
            if(dfs(a,node,visit)) return true;
        }
        return false;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();
        for(auto &a:edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
            vector<bool>visit(n+1, 0);

            if(dfs(a[0],-1,visit)) return {a[0],a[1]};
        }
        return {};
    }
};
