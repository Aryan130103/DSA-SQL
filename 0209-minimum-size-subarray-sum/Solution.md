# Sliding Window | C++

# Complexity
- Time complexity: O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int l=0,r=0;
        int len=INT_MAX,sum=0;
        while(r<n){
            sum+=nums[r];
            while(sum>=target){
                len=min(len,r-l+1);
                sum-=nums[l];
                l++;
            }
            r++;
        }
        return len==INT_MAX?0:len;
    }
};
```