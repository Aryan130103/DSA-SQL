class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int n=img1.size();
        vector<pair<int,int>> one,two;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(img1[i][j]==1)
                    one.push_back({i,j});
            
                if(img2[i][j]==1)
                    two.push_back({i,j});
            }
        }

        unordered_map<int,int> m;
        int maxx=0;
        for(auto [r1,c1]:one){
            for(auto [r2,c2]:two){
                int dr=r1-r2;
                int dc=c1-c2;
                int k=dr*100+dc;
                m[k]++;
                maxx=max(maxx,m[k]);
            }
        }
        return maxx;
    }
};