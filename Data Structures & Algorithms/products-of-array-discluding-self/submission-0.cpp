class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> res(nums.size(),0);
        int zeroes = 0, idx= -1, prod = 1;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==0) {
                zeroes++;
                idx = i;
            } else {
                prod = prod*nums[i];
            }
        }
        if(zeroes == 0){
            for(int i=0; i<nums.size();i++){
                res[i]=prod/nums[i];
            }
        } else if(zeroes == 1){
            res[idx] = prod;
        }
        return res;
    }
};
