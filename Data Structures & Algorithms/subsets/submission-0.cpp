class Solution {
public:
    vector<vector<int>> result;
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> current;
        dfs(nums,0,current);
        return result;
    }
private:
    void dfs(vector<int>&nums, int start, vector<int>&current){
        result.push_back(current);
        for(int i=start;i<nums.size();i++){
            current.push_back(nums[i]);
            dfs(nums,i+1,current);
        }
        current.pop_back();
    }
};
