class Solution {
public:
    int totalMoney(int n) {
        int k=n/7;
        int sum=(k*(2*28 + (k-1)*7))/2;

        for(int day=0;day<n%7;day++){
            sum += (k+1) +day;
        }
        return sum;
    }
};