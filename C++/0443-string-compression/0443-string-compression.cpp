class Solution {
public:
    int compress(vector<char>& chars) {
        int n=chars.size();
        if(n==1) return 1;

        int i=0,write=0;

        while(i<n){
            char ch=chars[i];
            int c=0;

            while(i<n && chars[i]==ch){
                i++;
                c++;
            }

            chars[write++]=ch;

            if(c>1){
                string s=to_string(c);
                for(auto& digit:s)
                    chars[write++]=digit;
            }
        }

        return write;
    }
};