class Solution {
public:
    vector<string> createGrid(int m, int n) {
        string s(n,'#');
        s[0]='.';
        vector<string> grid(m,s);
        for(int i=1;i<n;i++)
            grid[m-1][i]='.';
            
        return grid;
    }
};