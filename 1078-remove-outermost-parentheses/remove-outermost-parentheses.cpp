class Solution {
public:
    string removeOuterParentheses(string s) {
        string result = "";
        int balance = 0;
        
        for (char c : s) {
            if (c == '(') {
                if (balance > 0) {
                    result += c;
                }
                balance++;
            } else if (c == ')') {
                balance--;
                if (balance > 0) {
                result += c;
                }
            }
        }
        
        return result;
    }
};
