class Solution {
private:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[0]*a[0]+a[1]*a[1]<b[0]*b[0]+b[1]*b[1];
    }
public:
    vector<vector<int>> kClosest(vector<vector<int>>& p, int k) {
        sort(p.begin(),p.end(),cmp);

        return vector<vector<int>> (p.begin(),p.begin()+k);
    }
};