class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.length()>s2.length()) return false;
        unordered_map<char,int> count;
        for(int i=0;i<s1.length();i++) count[s1[i]]++;
        int l=0,r=s1.length();
        while(r<=s2.length()){
            unordered_map<char,int> count1;
            for(int i=l;i<r;i++) count1[s2[i]]++;
            if(count == count1) return true;
            l++;
            r++;
        }
        return false;
    }
};
