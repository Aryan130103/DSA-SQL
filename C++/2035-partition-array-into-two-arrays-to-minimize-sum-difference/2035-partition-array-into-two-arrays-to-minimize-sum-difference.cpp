class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(auto i:nums) sum+=i;
        int s=n/2;
        vector<vector<int>> left(s+1),right(s+1);

        for(int mask=0;mask<(1<<s);mask++){
            int lsum=0,rsum=0,cnt=0;
            for(int i=0;i<s;i++){
                if(mask&(1<<i)){
                    cnt++;
                    lsum+=nums[i];
                    rsum+=nums[i+s];
                }
            }
            left[cnt].push_back(lsum);
            right[cnt].push_back(rsum);
        }

        for(int i=0;i<=s;i++){
            sort(right[i].begin(),right[i].end());
        }

        int ans=INT_MAX;
        for(int k=0;k<=s;k++){
            auto &vec=right[s-k];
            for(int lsum:left[k]){
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