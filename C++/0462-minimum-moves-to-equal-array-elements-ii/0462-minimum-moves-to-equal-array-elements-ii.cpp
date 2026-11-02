class Solution {
private:
    int f(int l,int r,vector<int>& nums){
        int sum=0;
        while(l<=r){
            sum+=nums[l++];
        }
        return sum;
    }
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        int mid=n/2;

        int leftsum=f(0,mid,nums);
        int rightsum=f(mid+1,n-1,nums);

        int moves1= ((mid+1)*nums[mid])-leftsum;
        int moves2= rightsum-((n-1-mid)*nums[mid]);
        
        
        return moves1+moves2;
    }
};

