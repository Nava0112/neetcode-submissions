class Solution {
public:
    int calc(double i, vector<int>& piles){
        int cnt=0;
        for(auto a: piles){
            cnt += ceil((a/i));
        }
        return cnt;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = *max_element(piles.begin(), piles.end());
        int ans = high;
        while(low<=high){
            int mid = low + ( high - low )/2;
            if(calc(mid, piles) <= h){
                ans = mid;
                high = mid-1;
            }
            else low = mid+1;
        }
        return ans;
    }
};
