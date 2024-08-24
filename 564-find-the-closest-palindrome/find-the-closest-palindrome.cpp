class Solution {
public:
    string nearestPalindromic(string n) {
        int len = n.size();
        long long original = stoll(n);
        vector<long long> candidates; 
        candidates.push_back(pow(10, len) + 1); 
        candidates.push_back(pow(10, len - 1) - 1); 
        long long prefix = stoll(n.substr(0, (len + 1) / 2));
        for (int i = -1; i <= 1; ++i) {
            string newPrefix = to_string(prefix + i);
            string candidate = newPrefix + string(newPrefix.rbegin() + (len % 2), newPrefix.rend());
            candidates.push_back(stoll(candidate));
        } 
        long long closest = -1;
        for (long long cand : candidates) {
            if (cand != original) {
                if (closest == -1 || abs(cand - original) < abs(closest - original) ||
                    (abs(cand - original) == abs(closest - original) && cand < closest)) {
                    closest = cand;
                }
            }
        } 
        return to_string(closest);
    }
};