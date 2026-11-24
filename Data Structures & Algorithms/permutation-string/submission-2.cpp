class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s2.length()<s1.length()) return false;
        unordered_map<char,int> tracker;
        for(char c:s1){
            tracker[c]++;
        }
        int left=0,right=s1.length()-1;
        while(right<s2.length()){
            unordered_map<char,int> tracker1;
            for(int i=left;i<=right;i++) tracker1[s2[i]]++;
            if(tracker==tracker1) return true; 
            left++; 
            right++;
        }
        return false;
        
    }
};
