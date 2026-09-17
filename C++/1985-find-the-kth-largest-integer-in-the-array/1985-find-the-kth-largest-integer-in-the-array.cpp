class Solution {
    struct compare{
        bool operator()(const string& a,const string& b){
            if(a.size()!=b.size()) 
                return a.size()>b.size();
            return a>b;
        }
    };
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,compare> pq;

        for(auto& ch:nums){
            pq.push(ch);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};