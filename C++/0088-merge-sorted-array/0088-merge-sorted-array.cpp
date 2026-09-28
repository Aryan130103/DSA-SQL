class Solution {
public:
    void merge(vector<int>& nums1, int n, vector<int>& nums2, int m) {
        int i=n-1,j=m-1,x=n+m-1;
        while(j>=0){
            if(i>=0 && nums1[i]>nums2[j]){
                nums1[x--]=nums1[i--];
            }
            else
                nums1[x--]=nums2[j--];
        }
    }
};