class Solution {
public:
    int maxSum(vector<int>& nums, int k) {
        vector<int> bits(31,0);
        long long MOD=1e9+7;

        for(auto& n:nums){
            for(int i=0;i<31;i++){
                if(n&(1<<i))
                    bits[i]++;
            }
        }
        
        long long ans=0;
        while(k--){
            long long x=0;
            for(int i=0;i<31;i++){
                if(bits[i]>0){
                    x|=1LL<<i;
                    bits[i]--;
                }
            }
            ans=(ans+x*x)%MOD;
        }
        return ans;
    }
};