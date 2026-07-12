class Solution {
public:
    bool isHappy(int n) {
        unordered_set<int>st;
        while(!st.count(n)){
            if(n==1) return true;
            st.insert(n);
            int nn = n;
            int sum =0;
            while(nn>0){
                int r =nn%10;
                sum += r*r;
                nn/=10;
            }
            n=sum;
        }
        return false;
    }
};
