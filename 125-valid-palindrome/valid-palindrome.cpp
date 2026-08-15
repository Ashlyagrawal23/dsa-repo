class Solution {
public:
    bool isPalindrome(string s) {
       string t = "";
       for(auto it : s){
         if((65 <= int(it) && int(it) <= 90) || (97 <= int(it) && int(it) <= 122) || (48 <= int(it) && int(it) <= 57)){
            t += tolower(it);

             
         }
       }
       string ans = t;
       reverse(t.begin(),  t.end());

       string ans2 = t;
       if(ans != ans2)
        return false;

       else{
        return true;
       }



    }
};