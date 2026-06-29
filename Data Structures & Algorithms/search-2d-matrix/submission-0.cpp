class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        vector<int> temp;
        for(vector<int> vc: matrix){
            for(int tmp:vc) temp.push_back(tmp);
        }
        return binarySearch(temp,0,temp.size()-1,target);
    }
    bool binarySearch(vector<int> temp,int start, int end, int target){
        if(start>end) return false;
        int mid = start+(end-start)/2;
        if(temp[mid]==target) {
            return true;
        } else if(temp[mid]>target){
            return binarySearch(temp,start,mid-1,target);
        } else {
            return binarySearch(temp,mid+1,end,target);
        }
    }
};
