class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, vector<bool> &used, vector<int> &curr){
        if(nums.size()==curr.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(used[i]) continue;
            used[i]=true;
            curr.push_back(nums[i]);
            backtrack(nums,used,curr);
            curr.pop_back();
            used[i]=false;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> curr;
        vector<bool> used(nums.size(),false);
        backtrack(nums,used,curr);
        return ans;
        
        
    }
};
