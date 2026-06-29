class Solution {
public:
    int reverse(int x) {
        long reverse=0;
        while(x!=0){
            reverse=reverse*10+x%10;
            x/=10;
        }
        if(reverse<INT_MIN||reverse>INT_MAX) return 0;
        return reverse;      
    }
};
