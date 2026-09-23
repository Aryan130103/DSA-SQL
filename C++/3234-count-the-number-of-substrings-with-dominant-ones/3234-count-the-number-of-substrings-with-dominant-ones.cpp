class Solution {
public:
    int numberOfSubstrings(string s) {
        int n=s.size();
        vector<int> countones(n,0);
        countones[0]=(s[0]=='1')?1:0;

        for(int i=1;i<n;i++){
            countones[i]=countones[i-1]+(s[i]=='1'?1:0);
        }

        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                int ones=countones[j]-(i-1>=0?countones[i-1]:0);
                int zeros=(j-i+1)-ones;

                if(zeros*zeros>ones){
                    j+=zeros*zeros-ones-1;
                }
                else if(zeros*zeros==ones)
                    ans++;
                else{
                    ans++;
                    int k=sqrt(ones)-zeros;
                    int next=j+k;
                    if(next>=n){
                        ans+=n-j-1;
                        break;
                    }
                    else
                        ans+=k;
                    j=next;
                }
            }
        }
        return ans;
    }
};