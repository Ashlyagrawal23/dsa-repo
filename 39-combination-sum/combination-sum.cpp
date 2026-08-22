class Solution {
public:
    void solve(vector<int>& candidates, int target,int n, int idx, vector<int>& ds, int sum, vector<vector<int>>& ans ) {

        if(sum > target) {
            return;
        }
        if(idx == n){
            if(sum == target){
                ans.push_back(ds);
                
            }
            return;
        }
        ds.push_back(candidates[idx]);
        sum += candidates[idx];
        solve(candidates, target, n, idx, ds , sum, ans);
        ds.pop_back();
        sum -= candidates[idx];
        solve(candidates, target, n, idx + 1, ds, sum, ans);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target){
        vector<vector<int>> ans;
        vector<int> ds;
        solve(candidates, target, candidates.size(), 0, ds, 0, ans);
        return ans;


    }
};