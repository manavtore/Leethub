class Solution {
private:
    vector<vector<int>> dp;

private:
    int helper(vector<int> &piles, int i, int M)
    {
        if (i >= piles.size()) return 0;
        if (dp[i][M]) return dp[i][M];

        int ans = INT32_MIN;
        int sum = 0;

        for(int X = 0; X < 2 * M; ++X)
        {
            if (i + X < piles.size()) sum += piles[i + X];
            ans = max(ans, sum - helper(piles, i + X + 1, max(M, X + 1)));
        }

        return dp[i][M] = ans;
    }

public:
    int stoneGameII(vector<int>& piles) 
    {
        const int n = int(piles.size());
        dp.resize(n, vector<int> (2 * n));

        int total = accumulate(piles.begin(), piles.end(), 0); 
        int diff = helper(piles, 0, 1); 
        

        int ans = (total + diff) / 2;

        return ans;
    }
};