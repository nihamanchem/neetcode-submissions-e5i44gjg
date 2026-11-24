class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        vector<int> needed(26);
        vector<int> tracker(26);
        for(int i=0;i<s1.length();i++){
            needed[s1[i]-'a']++;
            tracker[s2[i]-'a']++;
        }
        if(needed==tracker) return true;
        for(int i=s1.length();i<s2.length();i++){
            tracker[s2[i-s1.length()]-'a']--;
            tracker[s2[i]-'a']++;
            if(needed==tracker) return true;
        }
        return false;
        
    }
};
