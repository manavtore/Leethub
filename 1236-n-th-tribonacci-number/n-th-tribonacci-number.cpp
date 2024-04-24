class Solution {
public:
    int tribonacci(int n) {
        if(n==0) return 0;
        if(n==1 || n==2) return 1;
        int t1=0,t2=1,t3=1;
        int tn;
        for(int i=3;i<=n;i++){
            tn=t1+t2+t3;
            t1=t2;
            t2=t3;
            t3=tn;
        }
        return tn;
    }
};