class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> m;

        int k=0;
        for(int i=0;i<n;i++){
            if(m[nums[i]]>=1) continue;
            else{
                m[nums[i]]++;
                nums[k++]=nums[i];
            }
        }
        return k;
    }
};