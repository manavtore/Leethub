class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26, 0);

        for (char ch : word) {
            freq[ch - 'a']++;
        }

        sort(freq.rbegin(), freq.rend());

        int push = 1;
        int ans = 0;

        for (int i = 0, cnt = 1; i < 26; i++) {
            if (freq[i] == 0) break;
            ans += freq[i] * push;

            if (cnt % 8 == 0) {
                push++;
            }
            cnt++;
        }

        return ans;
    }
};