class Solution {
public:
    int scoreOfString(string s) {
        int sum = 0;
        for(int i=1;i<s.length();i++){
            int current = s[i] - 'a';
            int prev = s[i-1] - 'a';
            sum +=  abs(current-prev);
        }
        return sum;
    }
};