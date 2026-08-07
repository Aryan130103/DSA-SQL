class Solution {
private:
    void dfs(string word, string beginWord, unordered_map<string,int>& m, vector<vector<string>>& ans,vector<string>& seq ){
        if(word==beginWord){
            reverse(seq.begin(),seq.end());
            ans.push_back(seq);
            reverse(seq.begin(),seq.end());            
        }
        int steps=m[word];
        for(int i=0;i<word.size();i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(m.count(word) && m[word]+1==steps){
                        seq.push_back(word);
                        dfs(word,beginWord,m,ans,seq);
                        seq.pop_back();
                    }
                }
                word[i]=og;
        }
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,int> m;
        unordered_set<string> st(wordList.begin(),wordList.end());
        vector<vector<string>> ans;
        queue<string> q;
        q.push(beginWord);
        m[beginWord]=1;
        st.erase(beginWord);
        while(!q.empty()){
            string word=q.front();
            q.pop();
            int steps=m[word];
            if(word==endWord) break;

            for(int i=0;i<word.size();i++){
                char og=word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push(word);
                        m[word]=steps+1;
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }

        if(m.count(endWord)){
            vector<string> seq={endWord};
            dfs(endWord,beginWord,m,ans,seq);
        }

        return ans;
    }
};