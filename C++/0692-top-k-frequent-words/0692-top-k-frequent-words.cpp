class Solution {
struct compare{
    bool operator()(const pair<int,string> &a,const pair<int,string> &b){
        if(a.first!=b.first)
            return b.first>a.first;
        return a.second>b.second;
    }
};
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int> m;
        for(auto& w:words) m[w]++;

        priority_queue<pair<int,string>,vector<pair<int,string>>,compare>pq;

        for(auto [k,v]:m){
            pq.push({v,k});
        }

        vector<string> ans;
        while(!pq.empty() && k>0){
            ans.push_back(pq.top().second);
            pq.pop();
            k--;
        }
    return ans;
    }
};