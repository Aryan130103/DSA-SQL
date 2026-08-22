class Solution {
private:
    bool f(string &s,int &i){
        if(s[i]=='t'){
            i++;
            return true;
        }
        if(s[i]=='f'){
            i++;
            return false;
        }

        char op=s[i];
        i+=2;
    
        vector<bool>vals;
        while(s[i]!=')'){
            if(s[i]==','){
                i++;
                continue;
            }
            vals.push_back(f(s,i));
        }
        i++;

        if(op=='!') return !vals[0];

        if(op=='&'){
            for(auto x:vals){
                if(!x) return false;
            }
            return true;
        }

        for(auto x:vals){
            if(x) return true;
        }

        return false;
    }
public:
    bool parseBoolExpr(string s) {
        int i=0;
        return f(s,i);
    }
};