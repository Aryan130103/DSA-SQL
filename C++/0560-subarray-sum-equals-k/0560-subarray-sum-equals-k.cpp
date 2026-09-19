class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> m;
        m[0]=1;
        int c=0;
        int sum=0;
        for(auto n:nums){
            sum+=n;
            if(m.find(sum-k)!=m.end())
                c+=m[sum-k];
            
            m[sum]++;
        }
        return c;
    }
};