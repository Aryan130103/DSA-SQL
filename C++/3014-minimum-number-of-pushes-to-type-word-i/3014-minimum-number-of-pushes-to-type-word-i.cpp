class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size();
        int blocks=n/8;
        int r=n%8;
        return (blocks*(blocks+1)*4)+r*(blocks+1);
    }
};