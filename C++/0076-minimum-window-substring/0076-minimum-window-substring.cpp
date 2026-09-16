class Solution {
public:
    string minWindow(string s, string t) {
        int n=s.size(),m=t.size();
        if(n<m) return "";
        unordered_map<char,int> mp;
        
        int len=INT_MAX,l=0,count=0,start=0;

        for(auto& ch:t) mp[ch]++;

        for(int r=0;r<n;r++){
            if(mp[s[r]]>0){
                count++;
            }
            mp[s[r]]--;

            while(count==m){
                if(r-l+1<len){
                    len=r-l+1;
                    start=l;
                }

                mp[s[l]]++;

                if(mp[s[l]]>0)
                    count--;

                l++;
            }
        }
        return len==INT_MAX?"":s.substr(start,len);
    }
};