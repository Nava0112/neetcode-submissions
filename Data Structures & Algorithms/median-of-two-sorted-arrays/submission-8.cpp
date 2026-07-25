class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0;
        int j=0;
        vector<int> temp(n+m);
        int k=0;
        while(i<n && j<m){
            if(nums1[i]<=nums2[j]){
                temp[k]=nums1[i];
                i++;
            }
            else {
                temp[k]=nums2[j];
                j++;
            }
            k++;
        }
        while(i<n){
            temp[k]=nums1[i];
            i++;
            k++;
        }
        while(j<m){
            temp[k]=nums2[j];
            j++;
            k++;
        }
        int mid = (n+m)/2;
        if((n+m)%2==0) {
            return (temp[mid] + temp[mid-1])/2.0;
        }
        return temp[mid];
    }
};
