class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int n=s.size();
        int ones=0;
        for(auto& it:s){
            if(it=='1') ones++;
        }
        vector<pair<char,int>> runs;
        string t= "1"+s+"1";
        for(int i=0;i<t.size();){
            int j=i;
            while(j<t.size() && t[j]==t[i]) j++;
            runs.push_back({t[i],j-i});
            i=j;
        }
        int ans=ones;
        for(int i=1;i+1<runs.size();i++){
            if(runs[i].first=='1' && runs[i-1].first=='0' && runs[i+1].first=='0'){
                int gain=runs[i-1].second+runs[i+1].second;
                ans=max(ans,gain+ones);
            }
        }   
        return ans;
    }
};