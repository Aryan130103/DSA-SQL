class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n=nums.size();
        int c1=0,c2=0;
        int p1=0,p2=0;
        vector<int> ans;
        int t=n/3;

        for(int i=0;i<n;i++){
            if(c1==0 && nums[i]!=p2){
                p1=nums[i];
                c1=1;
            }
            else if(c2==0 && nums[i]!=p1){
                p2=nums[i];
                c2=1;
            }
            else if(p1==nums[i])
                c1++;
            else if(p2==nums[i])
                c2++;
            else{
                c1--;
                c2--;
            }
        }

        c1=0,c2=0;
        for(auto& it:nums){
            if(it==p1) c1++;
            else if(it==p2) c2++;
        }

        if(c1>t) ans.push_back(p1);
        if(c2>t) ans.push_back(p2);

        return ans;
    }
};