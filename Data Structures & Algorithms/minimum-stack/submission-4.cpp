class MinStack {
public:
    stack<int>minst;
    stack<int>st;
    MinStack() {
        
    }
    
    void push(int val) {
        st.push(val);
        if(minst.empty()){
            minst.push(val);
        }
        else {
            minst.push(min(val,minst.top()));
        }
    }
    
    void pop() {
        minst.pop();
        st.pop();
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minst.top();
    }
};
