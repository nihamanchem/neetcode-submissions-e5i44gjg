class Solution {
public:
    int maxArea(vector<int>& heights) {
        int l=0,r=heights.size()-1;
        int maxAmount = 0;
        while(l<r){
            int width = r-l;
            maxAmount = max(maxAmount, width*min(heights[l],heights[r]));
            if(heights[l]<heights[r]) l++;
            else r--;
        }
        return maxAmount;
    }
};
