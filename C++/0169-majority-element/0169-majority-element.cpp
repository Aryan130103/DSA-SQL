class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int maxx=0,curr=0;
        for(auto& n:nums){
            if(maxx==0)  curr=n;
            if(n==curr) 
                maxx++;
            else 
                maxx--;           
        }
        return curr;
    }
};