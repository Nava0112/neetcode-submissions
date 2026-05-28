    class Solution {
    public:
        int minEatingSpeed(vector<int>& piles, int h) {
            int n=piles.size();
            int l=1, k=*max_element(piles.begin(),piles.end());
            int ans=k;
            while(l<=k){
                int mid = l + (k - l) / 2;
                int val= accumulate(piles.begin(), piles.end(), 0, [mid](int acc, int x) {
                return acc + ceil((double)x/mid);
            });
                if(val<=h){
                    ans=mid;
                    k=mid-1;
                }
                else l=mid+1;
            }
            return ans;
        }
    };
