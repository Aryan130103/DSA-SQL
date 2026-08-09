class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int n=word1.size(),m=word2.size();
        vector<int> last(m,-1);
        int j=m-1;
        for(int i=n-1;i>=0 && j>=0;i--){
            if(word1[i]==word2[j]){
                last[j]=i;
                j--;
            }
        }

        vector<int> ans;
        bool used=false;
        j=0;
        for(int i=0;i<n && j<m;i++){
            if(word1[i]==word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!used){
                if(j==m-1 || (last[j+1]!=-1 && i<last[j+1])){
                    used=true;
                    ans.push_back(i);
                    j++;
                }
            }
        }
        if(j!=m) return {};
        return ans;
    }
};