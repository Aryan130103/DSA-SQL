class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> pair;
        unordered_set<int> triplet;

        if(n==1) return n;
        
        for(int i=0;i<n;i++){
            for(int j=1+1;j<n;j++){
                pair.insert(nums[i]^nums[j]);
            }
        }

        for(auto it:pair){
            for(auto num:nums){
                triplet.insert(it^num);
            }
        }

        for(auto num:nums){
            triplet.insert(num);
        }

        return triplet.size();
    }
};