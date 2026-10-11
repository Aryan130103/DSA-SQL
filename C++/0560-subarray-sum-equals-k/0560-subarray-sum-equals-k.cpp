class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int> m;
        m[0]=1;
        int sum=0;
        int c=0;

        for(auto& n:nums){
            sum+=n;
            if(m.count(sum-k))
                c+=m[sum-k];
            
            m[sum]++;
        }
        return c;
    }
};