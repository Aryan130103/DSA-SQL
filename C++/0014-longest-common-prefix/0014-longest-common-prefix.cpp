class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n=strs.size();
        string prefix=strs[0];
        int len=prefix.size();
        for(int i=1;i<n;i++){
            string s=strs[i];
            while(len>s.size() || prefix.substr(0,len)!=s.substr(0,len)){
                len--;
                if(len==0) return "";
            }
        }
        return prefix.substr(0,len);
    }
};