class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        
        for(int i=n-1;i>=0;i--){
            if(i!=0 && digits[i]==9){
                digits[i]=0;
            }
            else if(i==0 && digits[i]==9){
                digits.push_back(0);
                digits[0]=1;
                break;
            }  
            else{
                digits[i]+=1;
                break;
            }  
        } 

        return digits;
    }
};