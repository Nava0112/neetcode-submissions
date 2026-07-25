class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        int i=0;
        int j=0;
        int mid = (n+m)/2;
        int k=0;
        int prev=-1;
        int curr=-1;
        while(i<n && j<m && k<=mid){
            prev=curr;
            if(nums1[i]<=nums2[j]){
                curr=nums1[i];
                i++;
            }
            else {
                curr=nums2[j];
                j++;
            }
            k++;
        }
        while(i<n && k<=mid){
            prev=curr;
            curr=nums1[i];
            i++;
            k++;
        }
        while(j<m && k<=mid){
            prev=curr;
            curr=nums2[j];
            j++;
            k++;
        }
        return ((n+m)%2==0)?(prev+curr)/2.0:curr;
    }
};
