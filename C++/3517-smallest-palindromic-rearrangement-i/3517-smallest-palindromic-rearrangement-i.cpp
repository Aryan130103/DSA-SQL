class Solution {
public:
    string smallestPalindrome(string s) {
        int n=s.size();
        if(n==1) return s;
        unordered_map<char,int> m;
        for(auto& i:s){
            m[i]++;
        }
        int l=0,r=n-1;
        
        for(char ch='a';ch<='z';ch++){
            while(m[ch]>=2){
                s[l++]=ch;
                s[r--]=ch;
                m[ch]-=2;
            }
        }
        
        if(l==r){
            for(char ch='a';ch<='z';ch++){
                if(m[ch]){
                s[l]=ch;
                break;
                }
            }
        }
    return s;
    }
};