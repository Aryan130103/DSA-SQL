class Solution {
public:
    double findMedianSortedArrays(vector<int>& a, vector<int>& b) {
        if(a.size()>b.size())
            swap(a,b);
        int n=a.size();
        int m=b.size();

        int total=n+m;
        int half=(total+1)/2;

        int l=0,r=n;

        while(l<=r){
            int i=l+(r-l)/2;
            int j= half-i;

            int al=(i==0)?INT_MIN:a[i-1];
            int ar=(i==n)?INT_MAX:a[i];

            int bl=(j==0)?INT_MIN:b[j-1];
            int br=(j==m)?INT_MAX:b[j];

            if(al<=br && bl<=ar){
                if(total%2) return max(al,bl);
                return (max(al,bl)+min(ar,br))/2.0;
            }
            else if(al>br) r=i-1;
            else
                l=i+1;
        }
        return 0;
    }   
};