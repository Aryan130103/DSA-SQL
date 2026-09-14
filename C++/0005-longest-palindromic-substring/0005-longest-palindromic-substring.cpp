class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        string ans="";
        for(int i=0;i<n;i++){
            int st=i,e=i;
            while(st>=0 && e<n && s[st]==s[e]){
                st--;
                e++;
            }
            string temp=s.substr(st+1,e-st-1);
            if(temp.size()>ans.size()) ans=temp;

            st=i;
            e=i+1;
            while(st>=0 && e<n && s[st]==s[e]){
                st--;
                e++;
            }
            temp=s.substr(st+1,e-st-1);
            if(temp.size()>ans.size()) ans=temp;
        }
        return ans;
    }
};