class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(banned.begin(),banned.end());
        unordered_map<string,int> m;

        string word;
        for(auto c:paragraph){
            if(isalpha(c)){
                word+=tolower(c);
            }
            else if(!word.empty()){
                if(st.find(word)==st.end())
                    m[word]++;
                
                word="";
            }
        }

        if(!word.empty() && st.find(word)==st.end())
            m[word]++;
        
        string ans="";
        int maxx=0;
        
        for(auto [key,value]:m){
            if(value>maxx){
                maxx=value;
                ans=key;
            }
        }
        return ans;
    }
};