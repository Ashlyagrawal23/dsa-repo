class Solution {
public:
    int minSwaps(string s) {
      int balance = 0;
      int  swap = 0;

        for(int i =0; i < s.size(); i++){
            if(s[i] == ']' ){
                balance--;
                if(balance < 0){
                    swap++;
                    balance = 1;
                }
            }
            else{
                balance++;
            }
        }
        return swap;

        
    }
};