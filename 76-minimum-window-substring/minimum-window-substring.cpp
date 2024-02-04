class Solution {
public:
   string minWindow(string s, string t) {
    unordered_map<char, int> charCount;
    int requiredChars = t.length();

    for (char c : t) {
        charCount[c]++;
    }

    int left = 0, right = 0, minLen = INT_MAX, minStart = 0;

    while (right < s.length()) {
        if (charCount[s[right]] > 0) {
            requiredChars--;
        }
        charCount[s[right]]--;

        while (requiredChars == 0) {
            if (right - left + 1 < minLen) {
                minLen = right - left + 1;
                minStart = left;
            }

            charCount[s[left]]++;
            if (charCount[s[left]] > 0) {
                requiredChars++;
            }

            left++;
        }

        right++;
    }

    return (minLen == INT_MAX) ? "" : s.substr(minStart, minLen);
}
};