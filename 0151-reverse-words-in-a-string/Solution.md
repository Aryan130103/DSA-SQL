# C++ | O(1) space | Clean Solution | 


# Complexity
- Time complexity: O(N)
<!-- Add your time complexity here, e.g. $$O(n)$$ -->

- Space complexity: O(1);
<!-- Add your space complexity here, e.g. $$O(n)$$ -->

# Code
```cpp []
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

        //space handling
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

        //if the question said only one space in between words then remove the above section of space handling
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
```