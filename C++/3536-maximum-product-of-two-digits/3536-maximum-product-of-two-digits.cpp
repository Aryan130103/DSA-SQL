class Solution {
public:
    int maxProduct(int n) {
        /*
        vector<int> ans;
        while(n>0){
            int r=n%10;
            ans.push_back(r);
            n=n/10;
        }
        sort(ans.begin(),ans.end());
        int x=ans.size()-1;
        return ans[x]*ans[x-1];*/

        int m1=0,m2=0;
        while(n>0){
            int r=n%10;
            if(r>=m1){
                m2=m1;
                m1=r;
            }
            else if(r>=m2)
                m2=r;
            n=n/10;
        }
        return m1*m2;
    }
};