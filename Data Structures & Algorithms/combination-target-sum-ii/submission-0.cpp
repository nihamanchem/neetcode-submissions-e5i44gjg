class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> curr;
        sort(candidates.begin(),candidates.end());
        backtrack(curr, candidates, 0, target);
        return ans;  
    }
    void backtrack(vector<int>& curr, vector<int>& candidates, int i, int target){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || i>=candidates.size()) return;
        curr.push_back(candidates[i]);
        backtrack(curr, candidates, i+1, target-candidates[i]);
        curr.pop_back();
        while(candidates[i]==candidates[i+1] && i<candidates.size()-1) i++;
        backtrack(curr, candidates,i+1,target);
    }
};
