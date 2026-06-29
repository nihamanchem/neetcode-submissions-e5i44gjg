class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // int sum=0,n=nums.size();
        // for(int i=0;i<n;i++) sum+=nums[i];
        // return n*(n+1)/2 - sum;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<=n;i++) ans^=i;
        for(int i=0;i<n;i++) ans^=nums[i];
        return ans;
        
    }
};
