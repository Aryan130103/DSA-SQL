class Solution {
public:
    bool isAnagram(string s, string t) {
        int a=s.size();
        int b=t.size();
        if(a!=b) return false;

        unordered_map<char,int> m;

        for(auto& i:s) m[i]++;

        for(auto& i:t){
            if(!m.count(i)) return false;
            m[i]--;
            if(m[i]<0)
                return false;
        }
        return true;
    }
};