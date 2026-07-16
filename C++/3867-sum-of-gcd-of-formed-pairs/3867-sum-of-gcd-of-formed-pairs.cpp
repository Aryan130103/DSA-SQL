class Solution {
public:
    /*long long gcd(long long minn,long long maxx){
        int x=minn;
        while(x!=0){
            if(minn%x==0 && maxx%x==0) return x;
            else
            x--;
        }
        return 0;
    }*/

    long long gcdSum(vector<int>& nums) {
        int n=nums.size();
       
        vector<int> prefixGod(n,0);
        int m=INT_MIN;

        for(int i=0;i<n;i++){
            m=max(m,nums[i]);
            prefixGod[i]=std::gcd(nums[i],m);            
        }
        sort(prefixGod.begin(),prefixGod.end());
        long long sum=0;
        int l=0,r=n-1;
        while(l<r){
            sum+=std::gcd(prefixGod[l],prefixGod[r]);
            r--;
            l++;
        }

        return sum;
    }
};