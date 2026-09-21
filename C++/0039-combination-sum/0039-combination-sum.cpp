class Solution {
private:
    void f(vector<int>& candidates, int target,int start,vector<int>& curr,vector<vector<int>>& res){
        if(target==0){
            res.push_back(curr);
            return;
        }

        for(int i=start;i<candidates.size();i++){
            if(candidates[i]>target) continue;
            curr.push_back(candidates[i]);
            f(candidates,target-candidates[i],i,curr,res);
            curr.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> curr;
        f(candidates,target,0,curr,res);
        return res;
    }
};