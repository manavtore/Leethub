class Solution {
public:
    long long wonderfulSubstrings(string word) {
     vector<long long> cnt(1024, 0);
        cnt[0] = 1;
        int mask = 0;
        long long ans = 0;
        for (char c : word) {
            int idx = c - 'a';
            mask ^= 1 << idx;
            ans += cnt[mask];
            for (int i = 0; i < 10; i++) {
                int lookFor = mask ^ (1 << i);
                ans += cnt[lookFor];
            }
            cnt[mask]++;
        }
        return ans;
    }
};