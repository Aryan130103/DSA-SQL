class Solution {
public:
    long long gcd(long long a,long long b){
        while(b){
            a%=b;
            swap(a,b);
        }
        return a;
    }

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
       
        vector<int> prefixGod(n,0);
        int m=INT_MIN;

        for(int i=0;i<n;i++){
            m=max(m,nums[i]);
            prefixGod[i]=gcd(nums[i],m);            
        }
        sort(prefixGod.begin(),prefixGod.end());
        long long sum=0;
        int l=0,r=n-1;
        while(l<r){
            sum+=gcd(prefixGod[l],prefixGod[r]);
            r--;
            l++;
        }

        return sum;
    }
};