# Most Optimal |  C++ | O(1) space | O(n) time | Easy solution

# Complexity
- Time complexity:O(n)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity:O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
class Solution {
public:
    int maxDepth(string s) {
        int c=0,maxx=0;
        for(auto& i:s){
            if(i=='(')
                maxx=max(maxx,++c);
            else if(i==')')
                c--;
        }
        return maxx;
    }
};
```