class Solution {
    unordered_map<long long,int> dp;
    long long findStreak(unordered_set<long long>& st,long long prev){
        if(dp.count(prev)) return dp[prev];

        long long square = prev * prev;

        if(square > 100000 || !st.count(square)){
            return dp[prev] = 1;
        }

        return dp[prev] = 1 + findStreak(st,square);
    }
public:
    int longestSquareStreak(vector<int>& nums) {
       unordered_set<long long> st(nums.begin(),nums.end());

       int streak = -1;

       for(int num:nums){
         int currStreak = findStreak(st,num);
            if( currStreak >= 2){
                streak = max(streak,currStreak);
            }
       }

        return streak;
    }
};