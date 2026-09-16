# C++ | Best solution to exist on discussion



# Code
```cpp []
class Solution {
public:
    bool isPalindrome(int x) {
        string y= to_string(x);
        int l=0,r=y.size()-1;
        while(l<r){
            if(y[l]!=y[r]) return false;
            l++;
            r--;
        }
        return true;
    }
};
```