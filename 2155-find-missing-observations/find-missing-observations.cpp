class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int totalSum = (m + n) * mean;
        int sum1 = 0;
        for(auto sum:rolls){
            sum1 += sum;
        }

        int remain = totalSum - sum1;

        if(remain<n || remain>n*6){
            return {};
        }

        vector<int> ans(n,1);
        remain -=n;

        for(int i=0;i<n && remain>0;i++){
           int sum = min(5,remain);
           ans[i]+=sum;
           remain-=sum;
        }
        return ans;
    }
};