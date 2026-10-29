class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int n=nums.size();
        int freq[101]={0};
        for(auto& i:nums)
            freq[i]++;
        
        queue<int> q;
        for(auto& i:nums){
            if(i!=val)
                q.push(i);
        }

        int i=0;
        while(!q.empty()){
            nums[i++]=q.front();
            q.pop();
        }
        
        for(int i=0;i<freq[val];i++)
            nums.pop_back();
        
        return nums.size();
    }
};