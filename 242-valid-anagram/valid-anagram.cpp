class Solution {
public:
    bool isAnagram(string s, string t) {
        map< char, int> mpp;
        map<char, int > mpp2;
        for(int i = 0; i < s.size(); i++){
            mpp[s[i]]++;
        }
        for(int i = 0; i < t.size(); i++){
            mpp2[t[i]]++;
        }

        if(mpp.size() == mpp2.size()){
           for(auto it : mpp){
            char key = it.first;
            if(mpp[key] !=  mpp2[key]){
                return false;
                
            }
           }


        }
        else{
            return false;
        }
       
        return true;
    
    
    }
};