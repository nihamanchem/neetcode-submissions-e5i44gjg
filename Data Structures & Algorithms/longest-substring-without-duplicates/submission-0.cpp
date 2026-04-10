class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0;
        int res=0;

        unordered_set<char> dupCheck;
        for (int r=0;r<s.length();r++){
            while(dupCheck.count(s[r])){
                dupCheck.erase(s[l]);
                l++;
            }
            dupCheck.insert(s[r]);
            res = max(res,r-l+1);
        }
        return res;
    }
};
