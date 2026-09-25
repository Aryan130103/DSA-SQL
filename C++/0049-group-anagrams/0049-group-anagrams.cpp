class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        
        for(auto it:strs){
            string x=it;
            sort(x.begin(),x.end());
            m[x].push_back(it);
        }

        vector<vector<string>> ans;
        for(auto [k,v]:m){
            ans.push_back(v);
        }
        return ans;
    }
};