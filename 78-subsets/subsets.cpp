class Solution {
public:
    vector<vector<int>> subsets(vector<int>& arr, int i, vector<int>& temp, vector<vector<int>>& ans) {

        if(i == arr.size()){
            ans.push_back(temp);
            return ans;

        }
        temp.push_back(arr[i]);
        subsets(arr, i+ 1, temp, ans);

        temp.pop_back();
        subsets(arr, i+ 1, temp, ans);

       return ans;
        
        
    }
    vector<vector<int>> subsets(vector<int>& arr){
        vector<vector<int>> ans;
        vector<int> temp;
        return subsets(arr, 0, temp, ans);
    }
};