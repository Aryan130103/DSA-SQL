class Solution {
public:
    int reverseDegree(string s) {
        unordered_map<char,int> m;
        int i=26;
        for(char ch='a';ch<='z';ch++){
            m[ch]=i--;
        }
        int sum=0;
   
        for(int i=0;i<s.size();i++){
            sum+=(i+1)*(m[s[i]]);
        }
        return sum;
    }
};