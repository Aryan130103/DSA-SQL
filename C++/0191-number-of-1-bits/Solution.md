# C++ | Bit Manipulation

# Complexity
- Time complexity: O(log n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int hammingWeight(int n) {
        int c=0;
        while(n){
            n=(n&n-1);
            c++;
        }
        return c;
    }
};
```