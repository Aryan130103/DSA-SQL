class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& c) {
        unordered_map<int,vector<int>> m;
        for(auto i:c){
            m[i[0]].push_back(i[1]);
        }
        int ans=2*n;
        for(auto it:m){
            vector<int> seats=it.second;
            bool left=true,mid=true,right=true;
            for(auto s:seats){
                if(s>=2 && s<=5) left=false;
                if(s>=4 && s<=7) mid=false;
                if(s>=6 && s<=9) right=false;
            }
            ans-=2;
        
            if(left && right) ans+=2;
            else if(left || mid || right) ans+=1;
        }
        return ans;
    }
};