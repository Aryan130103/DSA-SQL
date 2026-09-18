class Solution {
private:
    bool f(int start,string word,unordered_set<string>& st,vector<int>&dp){
        int l=word.size();
        if(start==l) return true;
        if(dp[start]!=-1) return dp[start];
        
        for(int i=start;i<l;i++){
            string pre=word.substr(start,i-start+1);
            string suf=word.substr(i+1);

            if(st.find(pre)!=st.end()){
                if(st.find(suf)!=st.end() || f(i+1,word,st,dp))
                    return dp[start]=true;
            }
        }
        return dp[start]=false;
    }
public:
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        unordered_set<string> st(words.begin(),words.end());
        vector<string> ans;
        for(auto & word:words){
            st.erase(word);
            vector<int>dp(word.size(),-1);
            if(f(0,word,st,dp))
                ans.push_back(word);
            
            st.insert(word);
        }
        return ans;
    }
};