class Solution {
public:
    bool binSearch(int low, int high, vector<int>&arr, int target){
        
        while(low<=high){
            int mid = low + (high-low)/2;
            if(arr[mid]==target) return 1;
            else if(target>=arr[mid]) return binSearch(mid+1, high, arr, target);
            else return binSearch(low, mid-1, arr, target);
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix[0].size();
        for(auto i: matrix){
            if(target>=i[0] && target<=i[n-1]) return binSearch(0,n-1, i, target);
        }
        return false;
    }
};
