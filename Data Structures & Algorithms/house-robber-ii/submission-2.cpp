class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==0) return 0;
        if(n==1) return nums[0];
        if(n==2) return max(nums[0],nums[1]);
        return max(helper(nums,1,nums.size()-1),helper(nums,0,nums.size()-2));
    }

    int helper(vector<int> &nums, int start, int end){
        vector<int> dp(end-start+1,0);
        dp[0]=nums[start];
        dp[1]=max(dp[0],nums[start+1]);
        for(int i=2;i<end-start+1;i++){
            dp[i]=max(dp[i-1],nums[start+i]+dp[i-2]);
        }
        return dp[end-start];
    }
};
