class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string,string> m;
        for(auto& it:knowledge){
            m[it[0]]=it[1];
        }

        int open=-1,close=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')
                open=i;
            if(s[i]==')')
                close=i;

            if(open!=-1 && close!=-1){
                string x=s.substr(open+1,close-open-1);
                
                string val;
                if(m.count(x))
                    val=m[x];
                else
                    val="?";

                int oldlen=close-open+1;
                s.replace(open,oldlen,val);

                i=open+val.size()-1;
                
                open=-1;
                close=-1;
            }
        }
        return s;
    }
};