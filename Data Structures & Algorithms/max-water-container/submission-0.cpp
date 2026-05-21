class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();
        int i=0, j=n-1;
        int sum=0;
        while(i<j){
            sum=max(sum,(j-i)*min(heights[i],heights[j]));
            if(heights[i]>=heights[j]) j--;
            else i++;
        }
        return sum;
    }
};
