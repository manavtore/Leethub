class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return "";
        long long prefix = 0, suffix = 0;
        int MOD = 1e9 +7;
        const int BASE = 29;
        long long power = 1;
        long long index = 0;

        for(int i=0;i<s.length();i++){
            int c = s[i] - 'a' +1;

            prefix = (prefix * BASE + c) %MOD;

            suffix = (suffix + c * power ) % MOD;

            power = (power * BASE) %MOD;
            if(prefix==suffix){
                index = i;
            }

        }
        string suff = s.substr(index + 1);

        reverse(suff.begin(),suff.end());

        return suff + s;

    }
};