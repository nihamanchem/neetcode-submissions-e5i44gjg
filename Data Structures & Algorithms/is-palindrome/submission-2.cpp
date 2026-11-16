class Solution {
public:
    bool isPalindrome(string s) {
        int left=0,right=s.length();
        while(left<right){
            while(!isalnum(static_cast<unsigned char>(s[left]))) left++;
            while(!isalnum(static_cast<unsigned char>(s[right]))) right--;
            if(left<right){
                if(tolower(static_cast<unsigned char>(s[left])) != tolower(static_cast<unsigned char>(s[right]))) return false;
                left++;
                right--;
            }
        }
        return true;
    }
};
