class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int currMax=nums[0],currMin=nums[0],resMax=nums[0];
        for(int i=1;i<nums.size();i++){
            int num = nums[i];
            int tempMax = max(num, max(currMax*num, currMin*num));
            int tempMin = min(num, min(currMax*num, currMin*num));
            currMax = tempMax;
            currMin = tempMin;
            resMax = max(currMax,resMax);
        }
        return resMax;
    }
};
