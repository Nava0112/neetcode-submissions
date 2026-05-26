class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n=matrix.size(), m=matrix[0].size();
        int low=0;
        int high=n*m-1;
        while(low<=high){
            int mid=(low+high)/2;
            int i=mid/m;
            int j=mid%m;
            int val=matrix[i][j];
            if(val==target) return 1;
            else if(val<target) low=mid+1;
            else high=mid-1;
        }
        return 0;
    }
};
