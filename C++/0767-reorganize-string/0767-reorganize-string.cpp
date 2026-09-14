class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int>m;
        for(auto& ch:s) m[ch]++;

        //max_heap
        priority_queue<pair<int,char>> pq;
        for(auto& [ch,freq]:m){
            pq.push({freq,ch});
        }

        string ans;
        while(pq.size()>=2){
            auto [f1,ch1]=pq.top();
            pq.pop();
            auto [f2,ch2]=pq.top();
            pq.pop();

            ans+=ch1;
            ans+=ch2;

            if(--f1>0) pq.push({f1,ch1});
            if(--f2>0) pq.push({f2,ch2});
        }

        if(!pq.empty()){
            auto [f,ch]=pq.top();
            if(f>1) return "";
            ans+=ch;
        }

        return ans;
    }
};