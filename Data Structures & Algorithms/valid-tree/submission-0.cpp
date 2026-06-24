class Solution {
private:
unordered_set<int>st;
unordered_map<int,vector<int>>graph;
public:
    bool dfs(int node, int pr){
        if(st.count(node)) return false;
        st.insert(node);
        for(auto a:graph[node]){
            if(a==pr) continue;
            if(!dfs(a, node)){
                return false;
            }
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges){
        for(auto a:edges){
            graph[a[0]].push_back(a[1]);
            graph[a[1]].push_back(a[0]);
        }
        if(!dfs(0,-1)) return false;
        return st.size()==n;
    }
};
