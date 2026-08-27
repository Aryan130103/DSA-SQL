class Solution {
public:
    string lexGreaterPermutation(string s, string t) {
        vector<int> c(26,0);
        int n=s.size();
        for(auto i:s) 
            c[i-'a']++;
        for(auto i:t)
            c[i-'a']--;

        for(int i=t.size()-1;i>=0;i--){
            int cur=t[i]-'a';
            c[cur]++;

            bool ok=true;
            for(int i=0;i<26;i++){
                if(c[i]<0){
                    ok=false;
                    break;
                }
            }

            if(!ok) continue;
             int next=-1;
            for(int i=cur+1;i<26;i++){
                if(c[i]>0){
                    next=i;
                    break;
                }
            }

            if(next==-1) continue;
            c[next]--;

            string ans=t.substr(0,i);
            ans+=char('a'+next);

            for(int i=0;i<26;i++){
                ans.append(c[i],char('a'+i));
            }   

            return ans;
        }
        return "";
    }
};