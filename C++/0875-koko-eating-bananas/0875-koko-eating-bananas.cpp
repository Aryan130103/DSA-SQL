class Solution {
private:
    bool finish(vector<int>& piles, int h, int k){
        long long hours=0;
        for(auto& p:piles){
            hours+=p/k;
            if(p%k!=0) hours++;
            if(hours>h) return false;
        }
        return true;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        int ans=r;

        while(l<=r){
            int mid=l+(r-l)/2;
            if(finish(piles,h,mid)){
                ans=mid;
                r=mid-1;
            }
            else
                l=mid+1;
        }
        return ans;
    }
};