class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx=*max_element(nums.begin(),nums.end());
        vector<long long>freq(mx+1,0);
        for(int x:nums)freq[x]++;

        vector<long long> multiples(mx+1,0);
        for(int g=1;g<=mx;g++){
            for(int k=g;k<=mx;k+=g){
                multiples[g]+=freq[k];
            }
        }

        vector<long long> exact(mx+1,0);
        for(int g=mx;g>=1;g--){
            long long c=multiples[g];
            long long total=c*(c-1)/2;
            for(int k=2*g;k<=mx;k+=g){
                total-=exact[k];
            }
            exact[g]=total;
        }

        //prefix sum
        vector<long long> pref(mx+1,0);
        for(int g=1;g<=mx;g++) pref[g]=pref[g-1]+exact[g];  

        //binary search
        vector<int> ans;
        ans.reserve(queries.size());
        for(long long it:queries){
            int l=1,h=mx,res=-1;
            while(l<=h){
                int mid=(l+h)/2;
                if(pref[mid]>it){
                    res=mid;
                    h=mid-1;
                }
                else
                l=mid+1;
            }
            ans.push_back(res);
        }
        return ans;
    }
};