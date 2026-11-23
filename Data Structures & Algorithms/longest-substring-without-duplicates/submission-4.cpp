class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tracker;
        int left=0,right=0,maxlength=0;
        while(right<s.length()){
            while(tracker.find(s[right])!=tracker.end()){
                tracker.erase(s[left]);
                left++;
            }
            tracker.insert(s[right]);
            maxlength = max(maxlength,right-left+1);
            right++;  
        }
        return maxlength;
    }
};
