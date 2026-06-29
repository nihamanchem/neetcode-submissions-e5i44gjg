class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> stk;
        vector<int> res(temperatures.size(),0);
        for(int i=0;i<temperatures.size();i++){
            while(!stk.empty() && temperatures[i]>stk.top().first){
                auto p = stk.top();
                stk.pop();
                res[p.second]=i-p.second;
            }
            stk.push({temperatures[i],i});
        }
        return res;
    }
};
