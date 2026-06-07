class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        if(stones.size()==0) return 0;
        if(stones.size()==1) return stones[0];
        priority_queue<int> pq;
        for(auto a: stones){
            pq.push(a);
        }
        int a=0;
        int b=0;
        while(pq.size()>1){
            a = pq.top();pq.pop();
            b = pq.top();pq.pop();
            pq.push(a-b);
        }
        return abs(a-b);
    }
};
