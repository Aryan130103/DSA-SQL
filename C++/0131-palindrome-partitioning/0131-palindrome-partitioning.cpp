class Solution {
private:
    bool palin(int l,int r,string& s){
        while(l<r){
            if(s[l]!=s[r])
                return false;
            l++;
            r--;
        }
        return true;
    }
    void f(int i,vector<string>& path,vector<vector<string>>& ans,string& s){
        if(i==s.size()) {
            ans.push_back(path);
            return;
        }
        
        for(int k=i;k<s.size();k++){
            if(palin(i,k,s)){
                path.push_back(s.substr(i,k-i+1));
                f(k+1,path,ans,s);
                path.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> path;
        vector<vector<string>> ans;
        f(0,path,ans,s);
        return ans;
    }
};