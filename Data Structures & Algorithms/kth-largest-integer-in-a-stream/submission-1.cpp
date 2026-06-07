class KthLargest {
public:
    int s;
    priority_queue<int,vector<int>,greater<int>> pq;
    KthLargest(int k, vector<int>& nums) {
        s=k;
        for(auto a:nums){
            pq.push(a);
            if(pq.size()>k) pq.pop();
        }
    }
    
    int add(int val) {
        pq.push(val);
        if(pq.size()>s) pq.pop();
        return pq.top();
    }
};
