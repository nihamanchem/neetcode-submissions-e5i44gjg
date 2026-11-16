class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> tracker;
        int left=0,ans=0;
        for(int right=0;right<s.length();right++){
            while(tracker.find(s[right])!=tracker.end()){
                tracker.erase(s[left]);
                left++;
            }
            tracker.insert(s[right]);
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};
