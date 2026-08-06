class Solution {
public:
    int minimumDifference(vector<int>& arr) {
        int sum=0;
        int n=arr.size()/2;
        for(auto i:arr) sum+=i;
        vector<vector<int>>left(n+1),right(n+1);

        for(int mask=0;mask<(1<<n);mask++){
            int lsum=0,rsum=0,cnt=0;
            for(int i=0;i<n;i++){
                if(mask&(1<<i)){
                    cnt++;
                    lsum+=arr[i];
                    rsum+=arr[i+n];                    
                }
            }
            left[cnt].push_back(lsum);
            right[cnt].push_back(rsum);
        }

        int ans=INT_MAX;
        for(int i=0;i<=n;i++){
            sort(right[i].begin(),right[i].end());
        }

        for(int i=0;i<=n;i++){
            auto& vec=right[n-i];
            for(auto lsum:left[i]){
                int target=sum/2-lsum;
                auto it=lower_bound(vec.begin(),vec.end(),target);

                if(it!=vec.end()){
                    int s1=*it+lsum;
                    ans=min(ans,abs(sum-2*s1));
                }

                if(it!=vec.begin()){
                    it--;
                    int s1=*it+lsum;
                    ans=min(ans,abs(sum-2*s1));
                }
            }
        }
    return ans;
    }
};