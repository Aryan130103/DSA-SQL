class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char,string> m1;
        unordered_map<string,char> m2;

        stringstream ss(s);
        string word;
        int i=0;

        while(ss>>word){
            if(i==pattern.size())
                return false;

            char c=pattern[i];
            if(m1.count(c)&& m1[c]!=word)
                return false;
            
            if(m2.count(word)&& m2[word]!=c)
                return false;

            m1[c]=word;
            m2[word]=c;
            i++;
        }
        return i==pattern.size();
    }
};