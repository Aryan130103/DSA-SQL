# C++ | Both Clockwise and Anticlockwise Solution | O(N) time | O(1) space


# Complexity
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1)
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Clockwise Code:
```cpp []
class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int n=grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        
        for(int i=0;i<n;i++)
            reverse(grid[i].begin(),grid[i].end());
    }
};
```

# AntiClockwise Code: 
```cpp []
class Solution {
public:
    void rotate(vector<vector<int>>& grid) {
        int n=grid.size();
        
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                swap(grid[i][j],grid[j][i]);
            }
        }
        
        reverse(grid.begin(),grid.end()); //only difference
    }
};
```