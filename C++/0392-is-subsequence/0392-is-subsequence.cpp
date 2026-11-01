class Solution {
public:
    bool isSubsequence(string s, string t) {
        int n=t.size();
        int m=s.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(j<m && s[j]==t[i]){
                j++;
            }
        }
        return j==m;
    }
};