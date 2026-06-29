class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> graph(numCourses);
        vector<int> indegree(numCourses);
        for(auto &it: prerequisites){
            graph[it[1]].push_back(it[0]);
            indegree[it[0]]++;
        }
        queue<int> q;
        vector<int> ans;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int num:graph[node]){
                indegree[num]--;
                if(indegree[num]==0){
                    q.push(num);
                }
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};