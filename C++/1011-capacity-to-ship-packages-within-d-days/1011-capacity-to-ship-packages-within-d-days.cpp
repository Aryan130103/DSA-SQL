class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);

        while(low<high){
            int mid=low+(high-low)/2;
            int sum=0;
            int daysneeded=1;

            for(auto& w:weights){
                if(sum+w>mid){
                    daysneeded++;
                    sum=w;
                }
                else
                    sum+=w;
            }

            if(daysneeded<=days)
                high=mid;
            else
                low=mid+1;
        }

        return low;
    }
};