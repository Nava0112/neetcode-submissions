class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m = nums2.size();
        int k = m+n;
        bool flag=0;
        if(k%2) flag=1;
        k=k/2;
        int i=0; int j=0;
        int prev=0; int curr=0;
        for(int cnt=0; cnt<=k; cnt++){
            prev=curr;
            if(i<n && (j>=m || nums1[i]<nums2[j])){
                curr=nums1[i];
                i++;
            }
            else {
                curr=nums2[j];
                j++;
            }
            cout<<cnt;
        }
        if(flag) return curr;
        return (double)(curr+prev)/2;
    }
};
