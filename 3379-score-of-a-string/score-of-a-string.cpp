class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;
        int prev = static_cast<int>(s[0]);
        for(int i=1;i<s.length();i++){
            int currChar = static_cast<int>(s[i]);
            int currScore = abs(prev - currChar);
            score += currScore;
            prev = currChar;
        }
        return score;
    }
};