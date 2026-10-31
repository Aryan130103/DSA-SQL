class Solution {
    void f(int l,int r,string& s){
        while(l<=r){
            swap(s[l++],s[r--]);
        }
    }
public:
    string reverseWords(string s) {
        int n=s.size();
        int j=0;
        for(int i=0;i<n;i++){
            if(s[i]!=' '){
                if(j>0) s[j++]=' ';
            }

            while(i<n && s[i]!=' '){
                s[j++]=s[i++];
            }
        }

        s.resize(j);

        reverse(s.begin(),s.end());
        int l=0,r=0;
        while(r<=s.size()){
            if(r==s.size() || s[r]==' '){
                f(l,r-1,s);
                l=r+1;
            }
            r++;
        }
        return s;
    }
};