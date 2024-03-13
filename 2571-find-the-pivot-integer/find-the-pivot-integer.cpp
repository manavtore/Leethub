class Solution {
public:
    int pivotInteger(int n) {
        if(n==1) return n; 
        int sum1=(n*(n+1))/2;
        int sum2=0;
        for(int i=1;i<=n;i++){
            if(sum2==sum1-i){
                return i;
            }
            sum2+=i;
            sum1-=i;
        }
        return -1;
    }
};