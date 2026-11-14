class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int zeroCount=0,product=1,zeroIndex=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {
                zeroCount++;
                if(zeroCount==1) zeroIndex = i;
            } else {
                product*=nums[i];
            }
        }
        vector<int> ans(nums.size(),0);
        if(zeroCount>=2) return ans;
        if(zeroCount==1){
            ans[zeroIndex]=product;
            return ans;
        }
        for(int i=0;i<nums.size();i++){
            ans[i]=product/nums[i];
        }
        return ans;

    }
};
