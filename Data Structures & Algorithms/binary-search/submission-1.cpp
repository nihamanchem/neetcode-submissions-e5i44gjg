class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.empty()) return -1;
        return binarySearch(nums,0,nums.size()-1,target);
    }
    int binarySearch(vector<int>& nums, int start,int end,int target){
        if(start>end) return -1;
        int mid = start+(end-start)/2;
        if(nums[mid]==target) {
            return mid;
        } else if(nums[mid]>target){
            return binarySearch(nums,start,mid-1,target);
        } else {
            return binarySearch(nums,mid+1,end,target);
        }
    }
};
