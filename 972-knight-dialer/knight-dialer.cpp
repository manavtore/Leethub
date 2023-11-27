#define ll long long int
#define MOD 1000000007
class Solution {
public:

    
    vector<vector<int>> jumps= {
        {4,6},
        {6,8},
        {7,9},
        {4,8},
        {3,9,0},
        {},
        {1,7,0},
        {2,6},
        {1,3},
        {4,2},
    };
    vector<vector<ll>> dp;
    ll solve(int rem,int digit){
        if(rem==0) return 1;

        if(dp[rem][digit]!=-1) return dp[rem][digit];

        ll ans=0;
        for(auto nextDigit : jumps[digit]){
            ans= (ans + solve(rem-1,nextDigit))%MOD;
        }
        return dp[rem][digit]=ans%MOD;
    }


    int knightDialer(int n) {
        dp.resize(n+1,vector<ll>(10,-1));
        ll ans=0;

        for(int digit=0;digit<10;digit++){
            ans=(ans + solve(n-1,digit))%MOD;
        }
        return (ans%MOD);
    }
};