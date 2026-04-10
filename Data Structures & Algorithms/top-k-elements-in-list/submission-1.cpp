class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> freqMap;
        for(int n: nums) freqMap[n]++;
        // priority_queue<pair<int,int>,vector<pair<int,int>>, greater<pair<int,int>>> minHeap;
        // for(auto& [num, freq]: freqMap){
        //     minHeap.push({freq,num});
        //     if(minHeap.size()>k) minHeap.pop();
        // }
        // vector<int> result;
        // while(!minHeap.empty()){
        //     result.push_back(minHeap.top().second);
        //     minHeap.pop();
        // }
        vector<vector<int>> buckets(nums.size()+1);
        for(auto& [num, freq] : freqMap){
            buckets[freq].push_back(num);
        }
        vector<int> result;
        for(int i=buckets.size()-1; i>=0 && result.size()<k; --i){
            for(int num: buckets[i]){
                result.push_back(num);
            }
        }
        return result;
        
    }
};
