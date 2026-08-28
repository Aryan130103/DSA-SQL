class Solution {
private:
    string solve(int i,string s,vector<int>& cnt,int mid,string& t, bool flag){
        if(s.size()==t.size()/2){
            string p=s;
            reverse(s.begin(),s.end());
            if(t.size()%2==1)
                p+=mid;
            p+=s;
            if(p>t)
                return p;
            return "";
        }
        for(int j=0;j<26;j++){
            if(cnt[j]==0) continue;
            if(!flag && char('a'+j)<t[i]) continue;

            cnt[j]--;
            s+=char('a'+j);
            bool newflag=flag;
            if(t[i]<char('a'+j))
                newflag=true;

            string ans=solve(i+1,s,cnt,mid,t,newflag);
            if(ans!="") return ans;
            s.pop_back();
            cnt[j]++;
        }
        return "";
    }
public:
    string lexPalindromicPermutation(string s, string target) {
        vector<int> cnt(26,0);
        for(auto i:s){
            cnt[i-'a']++;
        }
        int odd=0,mid=0;
        for(int i=0;i<26;i++){
            if(cnt[i]%2==1){
                odd++;
                mid=char(i+'a');
            }
            if(odd>1) return "";
            cnt[i]=cnt[i]/2;
        }
        string temp="";
        return solve(0,temp,cnt,mid,target,false);
    }
};