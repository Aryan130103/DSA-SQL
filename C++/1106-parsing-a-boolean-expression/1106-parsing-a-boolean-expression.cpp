class Solution {
private:
    int f(int& i,string& s){
        if(s[i]=='t'){
            i++;
            return true;
        } 
        if(s[i]=='f'){
            i++;
            return false;
        } 
        char og=s[i];
        i+=2;
        vector<bool> val;
        while(s[i]!=')'){
            if(s[i]==','){
                i++;
                continue;
            }
            val.push_back(f(i,s));
        }
        i++;
        
        if(og=='!') return !val[0];

        if(og=='&'){
            for(auto x:val){
                if(!x) return false;
            }
            return true;
        }

        for(auto x:val){
            if(x) return true;
        }
        return false;
    }
public:
    bool parseBoolExpr(string s) { 
        int i=0;
        return f(i,s);
    }
};