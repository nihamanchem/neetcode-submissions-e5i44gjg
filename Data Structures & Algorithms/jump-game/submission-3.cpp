class Solution {
public:
    bool canJump(vector<int>& nums) {
        int goal=0;
        for(int i=0;i<nums.size();i++){
            if(i>goal) return false;
            goal = max(goal,i+nums[i]);
        }
        return true;
    }
};
