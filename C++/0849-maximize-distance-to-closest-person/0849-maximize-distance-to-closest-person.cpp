class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int n=seats.size();
        int prev=-1,maxx=0;
        for(int i=0;i<n;i++){
            if(seats[i]==1){
                if(prev==-1)
                    maxx=i;
                else
                    maxx=max(maxx,(i-prev)/2);
                
                prev=i;
            }
        }
        maxx=max(maxx,(n-1-prev));
        return maxx;
    }
};