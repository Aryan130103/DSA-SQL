class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        st.erase(beginWord);
        while(!q.empty()){
            auto it=q.front();
            string word=it.first;
            int cnt=it.second;
            q.pop();
            if(word==endWord) return cnt;

            for(int i=0;i<word.size();i++){
                char og=word[i];
                for(auto ch='a';ch<='z';ch++){
                    word[i]=ch;
                    if(st.count(word)){
                        q.push({word,cnt+1});
                        st.erase(word);
                    }
                }
                word[i]=og;
            }
        }
        return 0;
    }
};