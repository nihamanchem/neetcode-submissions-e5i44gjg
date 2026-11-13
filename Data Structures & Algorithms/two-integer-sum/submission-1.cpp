class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> tracker;
        for(int i=0;i<nums.size();i++){
            if(tracker.find(target-nums[i])!=tracker.end()){
                return {tracker[target-nums[i]],i};
            } else {
                tracker[nums[i]]=i;
            }
        } 
        return {};       
    }
};
