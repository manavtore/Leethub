class Solution {
public:
    int totalMoney(int n) {
        long long int total=0;
        int initial=1;
        for(int days=1;days<=n;days++){
            total+= initial + ((days - 1) %7);
            if(days%7==0){
                initial++;
            }
        }
        return total;
    }
};