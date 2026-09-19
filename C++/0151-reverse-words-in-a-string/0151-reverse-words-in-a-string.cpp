class Solution {
    private:
        void rev(int l,int r,string &s){
            while(l<=r){
                swap(s[l],s[r]);
                l++;
                r--;
            }
        }
public:
    string reverseWords(string s) {
        int m=s.size();
        int j=0;
        for(int i=0;i<m;i++){
            if(s[i]!=' '){
                if(j>0) s[j++]=' ';

                while(i<m && s[i]!=' ')
                    s[j++]=s[i++];
            }
        }

        s.resize(j);

        //when only one psace in between words
        reverse(s.begin(),s.end());
        int n=s.size();
        int l=0,i=0;
        while(i<=n){
            if(i==n || s[i]==' ') {
                rev(l,i-1,s);
                l=i+1;
            }
            i++;
        }
        return s;
    }
};