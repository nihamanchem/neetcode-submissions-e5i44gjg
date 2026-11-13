class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        unordered_set<int> tracker;
        for(int num:nums){
            if(tracker.find(num)!=tracker.end()){
                return true;
            } else {
                tracker.insert(num);
            }
        }
        return false;
    }
};