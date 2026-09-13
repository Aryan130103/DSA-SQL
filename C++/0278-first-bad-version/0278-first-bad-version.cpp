// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l=1,r=n;
        int minn=INT_MAX;
        while(l<=r){
            int mid=l+(r-l)/2;
            bool x=isBadVersion(mid);
            if(x) minn=min(minn,mid);
            if(!x) l=mid+1;
            else
                r=mid-1;
        }
        return minn;
    }
};