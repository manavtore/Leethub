class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
        int currentSum = 0,maximumSum = 0, zeroSum=0 , n=customers.size();

        for(int i=0;i<n;i++){
            if(grumpy[i]==0) zeroSum+=customers[i];

            if(i<minutes){
                currentSum += (grumpy[i] == 1 ? customers[i] : 0 );
            }else{
                currentSum += (grumpy[i] == 1 ? customers[i] : 0) - (grumpy[i-minutes]==1 ? customers[i-minutes] : 0);
            }
            maximumSum = max(maximumSum,currentSum);
        }
        return maximumSum+zeroSum;
    }
};