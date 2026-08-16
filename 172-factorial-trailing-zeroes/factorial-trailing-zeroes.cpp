class Solution {
public:
    int trailingZeroes(int n) {

        if(n == 0){
           return 0;
        }
        n = n/5;
        return n + trailingZeroes(n);
        
        
    }
};