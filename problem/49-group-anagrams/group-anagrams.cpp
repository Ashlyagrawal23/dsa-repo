class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string>> mp;
        // key.  value
        // aet.   ["ate", tea , eat]
        // ant.    [tan , nat]
        // abt     [bat]

        for(int i = 0; i<strs.size();i++){
            string temp = strs[i];
            sort(strs[i].begin(), strs[i].end());

            mp[strs[i]].push_back(temp);

            
            
        }

        vector<vector<string>> ans;

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;




    }
};