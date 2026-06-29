class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0) return 0;
        priority_queue<int> pq;
        for(int stone : stones) pq.push(stone);
        while(pq.size()>1){
            int top1 = pq.top();
            pq.pop();
            int top2 = pq.top();
            pq.pop();
            pq.push(top1-top2);
        }
        return pq.top();    
    }
};
