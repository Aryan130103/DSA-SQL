class Solution {
public:
    int maxProduct(int n) {
        int p=1;
        vector<int> ans;
        while(n>0){
            int r=n%10;
            ans.push_back(r);
            n=n/10;
        }
        sort(ans.begin(),ans.end());
        int x=ans.size()-1;
        return ans[x]*ans[x-1];
    }
};