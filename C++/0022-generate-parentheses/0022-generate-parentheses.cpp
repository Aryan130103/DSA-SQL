class Solution {
private:
    void dfs(int op,int cp,string s,int n,vector<string>& ans){
        if(op==cp && op+cp==2*n){
            ans.push_back(s);
            return;
        }

        if(op<n){
            dfs(op+1,cp,s+"(",n,ans);
        }
        if(cp<op){
            dfs(op,cp+1,s+")",n,ans);
        }
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0,0,"",n,ans);
        return ans;
    }
};