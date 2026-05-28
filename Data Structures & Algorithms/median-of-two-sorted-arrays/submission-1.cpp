class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        if(n>m) return findMedianSortedArrays(nums2,nums1);
        int k=n+m;
        int h=ceil(k/2.0);
        for(int i=0; i<=n; i++){
            int l1=INT_MIN,l2=INT_MIN,r1=INT_MAX,r2=INT_MAX;
            if(i>0) l1=nums1[i-1];
            if(h-i > 0 && h-i-1 < m) l2 = nums2[h-i-1];
            if(i<n) r1=nums1[i];
            if(h-i<m) r2=nums2[h-i];
            if(l1<=r2 && l2<=r1){
                    if(k%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
                    return max(l1,l2);
            }
        }
        return 0;
    }
};
