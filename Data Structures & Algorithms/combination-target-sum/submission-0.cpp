class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> curr;
        backtrack(curr,nums,target,0);
        return ans;

        
    }

    void backtrack(vector<int>& curr, vector<int>& nums, int target, int i){
        if(target==0){
            ans.push_back(curr);
            return;
        }
        if(target<0 || i>=nums.size()){
            return;
        }
        curr.push_back(nums[i]);
        backtrack(curr,nums,target-nums[i],i);
        curr.pop_back();
        backtrack(curr,nums,target,i+1);
    }
};
