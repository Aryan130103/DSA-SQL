class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& in) {
        int n=in.size();
        sort(in.begin(),in.end());
        int s=in[0][0];
        int e=in[0][1];

        vector<vector<int>> ans;
        for(int i=1;i<n;i++){
            if(in[i][0]<=e)
                e=max(e,in[i][1]);
            else{
                ans.push_back({s,e});
                s=in[i][0];
                e=in[i][1];
            }
        }
        ans.push_back({s,e});
        return ans;
    }
};