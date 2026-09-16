class Solution {
public:
    string robotWithString(string s) {
        int n=s.size();
        stack<char> t;
        vector<char> mn(n);
        string ans="";

        mn[n-1]=s[n-1];
        for(int i=n-2;i>=0;i--){
            mn[i]=min(s[i],mn[i+1]);
        }

        for(int i=0;i<n;i++){
            t.push(s[i]);

            while(!t.empty() && (i==n-1 || t.top()<=mn[i+1])){
                ans+=t.top();
                t.pop();
            }
        }
        return ans;
    }
};