class Solution {
public:
    string minWindow(string s, string t) {
        if(t.length()==0) return "";
        vector<int> need(128,0);
        for(char c:t) need[c]++;
        string ans="";
        int missing = t.length(),left=0,minLeft=0,minLength=INT_MAX;
        for(int right=0;right<s.length();right++){
            if(need[s[right]]>0) missing--;
            need[s[right]]--;
            while(missing==0){
                int length = right-left+1;
                if(length<minLength){
                    minLength = length;
                    minLeft = left;
                }
                need[s[left]]++;
                if(need[s[left]]>0) missing++;
                left++;
            } 
        }
        return (minLength== INT_MAX) ? "" : s.substr(minLeft,minLength);
    }
};
