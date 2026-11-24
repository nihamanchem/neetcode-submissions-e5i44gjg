class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_set<char> tracker(s.begin(),s.end());
        int maxlen =0;
        for(char c : tracker){
            int left =0,count=0;
            for(int right=0;right<s.length();right++){
                if(s[right]==c) {
                    count++;  
                }
                while((right-left+1)-count>k){
                    if(s[left]==c){
                        count--;
                    }
                    left++;
                }
                maxlen = max(maxlen,right-left+1);
            }
        }
        return maxlen;
    }
};
