class Solution {
public:
    bool isPalindrome(string s) {
        int l=0,r=s.size()-1;
        string t;
        for(auto c:s){
            if(isalpha(c)) t+=tolower(c);
            else if(isdigit(c)) t+=c;
        }

        string x=t;
        reverse(x.begin(),x.end());
        return x==t;

    }
};