class Solution {
public:
    int maxDiff(int num) {
        string n=to_string(num);
        string a=n,b=n;

        for(int i=0;i<a.size();i++){
            if(a[i]!='9'){
                char x=a[i];
                for(auto& c:a){
                    if(c==x) c='9';
                }
                break;
            }
        }

        if(b[0]!='1'){
            char x=b[0];
            for(auto& c:b)
                if(c==x) c='1';
        }
        else{
            for(int i=1;i<b.size();i++){
                if(b[i]!='1' && b[i]!='0'){
                    char x=b[i];
                    for(auto& c:b)
                        if(c==x) c='0';
                    
                    break;
                }
            }
        }
        return stoi(a)-stoi(b);
    }
};