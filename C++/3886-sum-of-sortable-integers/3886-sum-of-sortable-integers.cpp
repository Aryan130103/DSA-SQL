class Solution {
public:
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        vector<int> div;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){ 
                div.push_back(i);
                if(i!=n/i) div.push_back(n/i);
            }
        }

        int ans=0;
        for(auto& k:div){
            int prevmax=0;
            bool ok=true;
            for(int s=0;s<n;s+=k){
                int drop=0;
                int mn=nums[0],mx=nums[0];
                int e=s+k-1;

                for(int j=s;j<=e;j++){
                    mn=min(mn,nums[j]);
                    mx=max(mx,nums[j]);

                    if(j<e && nums[j]>nums[j+1])
                        drop++;
                }

                if(nums[e]>nums[s]) drop++;

                if(drop>1){
                    ok=false;
                    break;
                }

                if(prevmax>mn && s>0){
                    ok=false;
                    break;
                }
                prevmax=mx;
            }
            if(ok)
                ans+=k;
        }
        return ans;
    }
};