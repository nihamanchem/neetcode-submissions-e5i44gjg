class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        if(edges.size()!=n-1) return false;
        vector<vector<int>> graph(n);
        for(auto &it: edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        vector<bool> visited(n, false);
        visited[0] = true;
        dfs(graph,visited,0);
        
        for(auto it: visited){
            if(!it) return false;
        }
        return true;

    }
    void dfs(vector<vector<int>> &graph, vector<bool> &visited,int curr){
        visited[curr]=true;
        for(int nei : graph[curr]){
            if(!visited[nei]){
                dfs(graph, visited, nei);
            }
        }
    }
};
