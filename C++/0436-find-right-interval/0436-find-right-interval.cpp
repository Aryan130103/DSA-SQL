class Solution {
private:
    int f(int e,vector<pair<int,int>>& x){
        int n=x.size();
        int l=0,r=n-1;
        int ans=-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(x[mid].first>=e) {
                ans=x[mid].second;
                r=mid-1;
            }
            else l=mid+1;
        }   
        return ans;
    }
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<pair<int,int>>x;
        for(int i=0;i<n;i++){
            x.push_back({intervals[i][0],i});
        }
        vector<int> ans(n,-1);
        sort(x.begin(),x.end());

        for(int i=0;i<n;i++){
            int e=intervals[i][1];
            ans[i]=f(e,x);
        }
        return ans;
    }
};