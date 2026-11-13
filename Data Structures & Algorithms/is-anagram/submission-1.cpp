class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;
        unordered_map<char,int> tracker;
        for(char c:s){
            tracker[c]++;
        }
        for(char c:t){
            tracker[c]--;
        }
        for(auto &it:tracker){
            if(it.second!=0) return false;
        }
        return true;
    }
};
