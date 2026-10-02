class Solution {
public:
    vector<string> getFolderNames(vector<string>& names) {
        vector<string> ans;
        unordered_map<string,int> m;

        for(auto& i:names){
            int c=m[i]++;
            if(c==0)
                ans.push_back(i);
            else{
                while(m.count(i+"("+to_string(c)+")"))
                    c++;

                string x=i+"("+to_string(c)+")";
                ans.push_back(x);
                
                m[i]=c+1;
                m[x]=1;
            }
        }
        return ans;
    }
};