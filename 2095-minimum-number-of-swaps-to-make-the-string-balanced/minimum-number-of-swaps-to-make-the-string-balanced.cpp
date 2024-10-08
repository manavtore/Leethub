class Solution {
public:
    int minSwaps(string s) {
        int bracket = 0;
        int maxBracket = 0;
        for(char c:s){
            if(c == ']'){
                bracket++;
                maxBracket = max( maxBracket , bracket);
            }else{
                bracket--;
            }
        }
        return (maxBracket + 1) / 2;
    }
};