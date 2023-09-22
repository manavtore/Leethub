class Solution {
public:
    string reverseWords(string s) {
        string result = "";
        int end = s.length() - 1;

        while (end >= 0) {
            while (end >= 0 && s[end] == ' ') {
                end--;
            }
            int start = end;
            while (start >= 0 && s[start] != ' ') {
                start--;
            }
            result += s.substr(start + 1, end - start);  
            if (start >= 0 && end > start) {
                result += ' ';  
            }

            end = start;
        }
          while (!result.empty() && result.back() == ' ') {
            result.pop_back();
        }

        return result;
    }
};
