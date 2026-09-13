class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n=envelopes.size();
        if(n==0) return 0;
        sort(envelopes.begin(),envelopes.end(),[](auto &a,auto &b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });

        vector<int> lis;

        for(auto &e:envelopes){
            int h=e[1];
            int l=0,r=lis.size()-1;
            while(l<=r){
                int mid=l+(r-l)/2;
                if(lis[mid]<h)
                    l=mid+1;
                else
                    r=mid-1;
            }
            if(l==lis.size())
                lis.push_back(h);
            else
                lis[l]=h;
        }
    return lis.size();
    }
};