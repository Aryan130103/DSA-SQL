class Solution {
public:
    int lengthOfLastWord(string s) {
        int r=s.size()-1;
        
        int c=0;
        while(r>=0){
            if(isalpha(s[r]))
                break;
            r--;
        }
        int l=r;

        while(l>=0){
            if(s[l]==' ') break;
            l--;
        }

        return r-l;
    }
};