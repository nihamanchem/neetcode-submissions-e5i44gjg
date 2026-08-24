class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int> tracker;
        while(tracker.find(n)==tracker.end()){
            tracker.insert(n);
            n = sumOfSquares(n);
            if(n==1) return true;
        }
        return false;     
    }
private:
    int sumOfSquares(int n){
        int output =0;
        while(n>0){
            int dig = n%10;
            output+=(dig*dig);
            n/=10;
        }
        return output;
    }
};
