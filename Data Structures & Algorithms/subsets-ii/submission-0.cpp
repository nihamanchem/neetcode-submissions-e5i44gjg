class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int> &nums, vector<int> &curr, int index){
        ans.push_back(curr);
        for(int i=index;i<nums.size();i++){
            if(nums[i]==nums[i-1] && i>index) continue;
            curr.push_back(nums[i]);
            backtrack(nums,curr,i+1);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int> curr;
        backtrack(nums,curr,0);
        return ans;
    }
};
