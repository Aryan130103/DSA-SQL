class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long first=LLONG_MIN,second=LLONG_MIN,third=LLONG_MIN;

        for(auto& x:nums){
            if(x>first){
                third=second;
                second=first;
                first=x;
            }
            else if(x>second && x!=first){
                third=second;
                second=x;
            }
            else if(x>third && x!=second && x!=first)
                third=x;
        }
        return third==LLONG_MIN?first:third;
    }
};