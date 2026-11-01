class Solution {
private:
    bool f(string s){
        int l=0,r=s.size()-1;
        while(l<r){
            if(s[l++]!=s[r--])
                return false;
        }
        return true;
    }
public:
    bool isPalindrome(string s) {
        int j=0;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(isalnum(s[i]))
                s[j++]=tolower(s[i]);
        }
        s.resize(j);
        cout<<s;
        return f(s);
    }
};