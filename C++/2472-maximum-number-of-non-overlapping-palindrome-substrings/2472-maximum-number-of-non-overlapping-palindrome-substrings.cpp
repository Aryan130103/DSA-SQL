class Solution {
private:
    bool pal(int l,int r,string& s){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
public:
    int maxPalindromes(string s, int k) {
        int n=s.size();
        if(k==1) return n;

        int nextstart=0;
        int cnt=0;
        for(int r=k-1;r<n;r++){
            int l=r-k+1;
            bool add=false;

            if(l>=nextstart && pal(l,r,s))
                add=true;
            else if(l>nextstart && pal(l-1,r,s))
                add=true;

            if(add){
                cnt++;
                nextstart=r+1;
            }
        }
        return cnt;
    }
};