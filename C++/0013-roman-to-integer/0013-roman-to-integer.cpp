class Solution {
public:
    int romanToInt(string s) {
        int res=0;
        unordered_map<char,int> m{
            {'I',1},{'V',5},{'X',10},{'L',50},{'C',100},{'D',500},{'M',1000}
        };

        int n=s.size();
        for(int i=1;i<n;i++){
            if(m[s[i-1]]<m[s[i]])
                res-=m[s[i-1]];
            else
                res+=m[s[i-1]];
        }
        return res+m[s[n-1]];
    }
};