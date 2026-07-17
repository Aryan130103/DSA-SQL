class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<int> freq(mx+1,0);
        vector<long long> GCD(mx+1,0);

        for(auto& it:nums) freq[it]++;
        
        for(int i=mx;i>0;i--){
            long long sum=0,extra=0;
            for(int j=i;j<=mx;j+=i){
                sum+=freq[j];
                extra+=GCD[j];
            }
            GCD[i]=sum*(sum-1)/2-extra;
        }
        partial_sum(GCD.begin(),GCD.end(),GCD.begin());

        vector<int> ans(queries.size());
        for(int i=0;i<queries.size();i++){
            ans[i]=ranges::upper_bound(GCD,queries[i])-GCD.begin();
        }
        
        return ans;
    }
};