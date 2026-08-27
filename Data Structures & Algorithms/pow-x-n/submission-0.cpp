class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0;
        if(n==0) return 1;
        double res = myPow(x,abs(n/2));
        res = res*res;
        if(n%2!=0) res=res*x;
        return (n<0) ? 1/res : res;
    }
};
