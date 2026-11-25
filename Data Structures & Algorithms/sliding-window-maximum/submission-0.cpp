class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> candidates;
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            while(!candidates.empty() && candidates.front()<=i-k){
                candidates.pop_front();
            }
            while(!candidates.empty() && nums[i]>=nums[candidates.back()]){
                candidates.pop_back();
            }
            candidates.push_back(i);
            if(i>=k-1) ans.push_back(nums[candidates.front()]);
        }
        return ans;
    }
};
