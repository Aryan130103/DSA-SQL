class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n=nums.size();
        int s=nums[0];
        unordered_map<int,int> m;
        for(auto i:nums){
            m[i]++;
        }

        for(int i=1;i<n;i++){
            if(nums[i]-nums[i-1]==1){
                s+=nums[i];
            }
            else break;
        }
        
        while(m.find(s)!=m.end()){
            s++;
        }
    return s;
    }
};