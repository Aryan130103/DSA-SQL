class Solution {
public:
    int strStr(string haystack, string needle) {
        int n=haystack.size();
        int m=needle.size();
        

        for(int l=0;l+m<=n;l++){
            int idx=0;
            while(idx<m && haystack[l+idx]==needle[idx]){
               idx++;
            }

            if(idx==m) return l;
        }
        return -1;
    }
};