class Solution {
public:
    string convert(string s, int numRows) {
        int n=s.size();
        if(n<=1 || numRows==1 || numRows>=n) return s;
        vector<string> row(numRows,"");

        int curr=0;
        int direction=1;
        for(auto&c:s){
            row[curr]+=c;

            if(curr==0)
                direction=1;
            else if(curr==numRows-1)
                direction=-1;
            
            curr+=direction;
        }

        string ans;
        for(auto& r:row)
            ans+=r;

        return ans;

    }
};