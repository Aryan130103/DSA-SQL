class Solution {
public:
    int maxDepth(string s) {
        int c=0,maxx=0;
        for(auto& i:s){
            if(i=='(')
                maxx=max(maxx,++c);
            else if(i==')')
                c--;
        }
        return maxx;
    }
};