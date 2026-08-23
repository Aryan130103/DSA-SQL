class Solution {
public:
    bool sumGame(string nums) {
        int n=nums.size();
        int s1=0,s2=0,q1=0,q2=0;
        for(int i=0;i<n/2;i++){
            if(nums[i]=='?')
                q1++;
            else
                s1+=nums[i]-'0';
        }
        for(int i=n/2;i<n;i++){
            if(nums[i]=='?')
                q2++;
            else
                s2+=nums[i]-'0';
        }
        if((q1+q2)%2) return true;
        return (s1-s2)!=9*(q2-q1)/2;
    }
};