class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int left=1;
        int right=*max_element(piles.begin(),piles.end());
        while(left<=right){
            int mid=left+(right-left)/2;
            int tmp=0;
            for(int pile:piles){
                tmp+=(pile+mid-1)/mid;
            }
            if(tmp<=h){
                ans=mid;
                right=mid-1;
            } else {
                left=mid+1;
            }
        }
        return ans;
        
    }
};
