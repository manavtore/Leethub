class Solution {
    bool check(string& a,string& b){
        if(a.size()!=b.size() -1){
            return false;
        }
        int first = 0;
        int second = 0;


        while(first<a.size() && second<b.size()){
            if(a[first]==b[second]){
                first++;
            }
            second++;
        }

        return first == a.size();
    }
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](const string& a, const string& b) {
            return a.size() < b.size();
        });


        int n = words.size();
        vector<int> dp(n,1);
        int maxlength = 1;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(check(words[j],words[i]) && dp[i] < dp[j]+1){
                    dp[i] = dp[j]+1;
                }
            }
           maxlength = max(maxlength, dp[i]);
        }
        return maxlength;
    }
};