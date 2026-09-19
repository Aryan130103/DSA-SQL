class Solution {
public:
    vector<string> fizzBuzz(int n) {
        vector<string> ans(n);
        for(int i=1;i<=n;i++){
            string s;
            
            if(i%3==0) s+="Fizz";
            if(i%5==0) s+="Buzz";

            ans[i-1]=(s.empty())?to_string(i):s;
        }
        return ans;
    }
};