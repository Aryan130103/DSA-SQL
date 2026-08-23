class Solution {
private:
    vector<int> f(int x){
        vector<int> v;
        for(int i=2;i*i<=x;i++){
            if(x%i==0){
                v.push_back(i);
                while(x%i==0) x/=i;
            }
        }
        if(x>1) v.push_back(x);
        return v;
    }
public:
    int distinctPrimeFactors(vector<int>& nums) {
        unordered_set<int> ans;
        for(auto i:nums)
            for(auto p:f(i)){
                ans.insert(p);
            }

        return ans.size();
    }
};