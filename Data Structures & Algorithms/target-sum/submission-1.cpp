class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>> dp(nums.size()+1,vector<int>(2*sum+1,-1));
        return backtrack(nums,0,0,target,sum,dp);
    }

    int backtrack(vector<int> nums, int i, int sum, int target, int offset,
    vector<vector<int>> &dp){
        if(i==nums.size()){
            return sum==target;
        }
        if(dp[i][sum+offset]!=-1) return dp[i][sum+offset];    
    dp[i][sum+offset] = backtrack(nums,i+1,sum+nums[i],target,offset,dp)+backtrack(nums,i+1,sum-nums[i],target,offset,dp);
        return dp[i][sum+offset];
    }
};
