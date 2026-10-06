class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(auto& n:nums) x^=n;

        long long bit=x&(-x);

        int a=0,b=0;
        for(auto& n:nums){
            if(n&bit)
                a^=n;
            else
                b^=n;
        }
        return {a,b};
    }
};