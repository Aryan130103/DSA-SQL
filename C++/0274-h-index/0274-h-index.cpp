class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        vector<int> freq(n+1,0);

        for(auto& c:citations){
            freq[min(c,n)]++;
        }

        int cnt=0;
        for(int i=n;i>=0;i--){
            cnt+=freq[i];
            if(cnt>=i) 
                return i;
        }

        return 0;
    }
};