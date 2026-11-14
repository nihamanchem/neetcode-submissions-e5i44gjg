class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> tracker(nums.begin(),nums.end());
        int maxStreak=0;
        for(int num:nums){
            if(tracker.find(num-1)==tracker.end()){
                int numStreak = 1;
                while(tracker.find(num+numStreak)!=tracker.end()){
                    numStreak++;
                }
                maxStreak = max(maxStreak,numStreak);
            }
        }
        return maxStreak;
        
    }
};
