class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> res;
        res.push_back(intervals[0]);
        for(auto &interval : intervals) {
            int begin = interval[0];
            int end = interval[1];
            int lastIntervalEnd = res.back()[1];
            if(begin<=lastIntervalEnd){
                res.back()[1] = max(end,lastIntervalEnd);
            } else {
                res.push_back(interval);
            }
        }
        return res;
    }
};
