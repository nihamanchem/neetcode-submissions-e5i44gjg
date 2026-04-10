class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int res = 0, maxFreq = 0;
        unordered_map<char,int> count;
        for(int r=0;r<s.length();r++){
            count[s[r]]++;
            maxFreq = max(maxFreq, count[s[r]]);
            if((r-l+1)-maxFreq<=k){
                res = max(res, r-l+1);
            } else {
                count[s[l]]--;
                l++;
            };
            
        }
        return res;
    }
};
