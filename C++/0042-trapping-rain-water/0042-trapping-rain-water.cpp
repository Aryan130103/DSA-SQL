class Solution {
public:
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1;
        int lmax=0,rmax=0;
        int rain=0;

        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);

            if(lmax<=rmax)
                rain+=lmax-h[l++];
            else
                rain+=rmax-h[r--];
        }
        return rain;
    }
};