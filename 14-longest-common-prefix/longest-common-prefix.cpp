class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = strs[0].size();
        for(int i = 1; i < strs.size(); i++){
            min_len = min(min_len, (int)strs[i].size());
        }
        string prefix = "";
        for(int i =0; i < min_len; i++){
            char c = strs[0][i];
            for(int j = 1; j < strs.size(); j++){
                if(strs[j][i] != c){
                    return prefix;
                }
            }
            prefix +=  c;
        }
        return prefix;
        
    }
};