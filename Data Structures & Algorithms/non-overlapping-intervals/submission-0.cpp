class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int count=0;
        sort(intervals.begin(),intervals.end());
        int n=intervals.size(),i=0;
        while(i<n-1){
            if(intervals[i+1][0]<intervals[i][1]){
                count++;
                intervals[i+1][1]=min(intervals[i][1],intervals[i+1][1]);
            }
            i++;
        }
        return count;
    }
};
