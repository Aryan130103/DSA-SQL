class Solution {
private:
    void dfs(int op,int cp,string s,vector<string>& ans,int n){
        if(op==cp && s.size()==2*n){
            ans.push_back(s);
            return;
        }

        if(op<n)
            dfs(op+1,cp,s+"(",ans,n);
        
        if(cp<op)
            dfs(op,cp+1,s+")",ans,n);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        dfs(0,0,"",ans,n);
        return ans;
    }
};