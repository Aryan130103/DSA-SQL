class Solution {
private:
    int f(vector<int> x){
        int ans=0;
        for(auto& i:x) ans^=i;

        return ans;
    }
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n=nums.size();
        for(int mask=0;mask<(1<<n);mask++){
            vector<int> temp;
            for(int i=0;i<n;i++){
                if(mask&(1<<i))
                    temp.push_back(nums[i]);
            }
            ans.push_back(temp);
        }

        int sum=0;
        for(auto& it: ans){
            sum+=f(it);
        }

        return sum;
    }
};