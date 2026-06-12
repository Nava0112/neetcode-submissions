class MedianFinder {
private:
priority_queue<int,vector<int>,greater<int>>minq;
priority_queue<int>maxq;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if(maxq.empty() || num<=maxq.top()) {
            maxq.push(num);
        }
        else minq.push(num);
        if(minq.size()>maxq.size()+1){
            maxq.push(minq.top());
            minq.pop();
        }
        if(minq.size()+1<maxq.size()){
            minq.push(maxq.top());
            maxq.pop();
        }
        
    }
    
    double findMedian() {
        if((minq.size()>maxq.size())) return minq.top();
        else if((minq.size()<maxq.size())) return maxq.top();
        else return (minq.top()+maxq.top())/2.0;
    }
};
