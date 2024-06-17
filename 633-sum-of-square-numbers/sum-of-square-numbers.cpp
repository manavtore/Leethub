class Solution {
public:
    bool judgeSquareSum(int c) {
        if(c<0) return false;
        int i=0;
        long long j=static_cast<long long>(sqrt(c));
        while(i<=j){
           long long sum = static_cast<long long>(i)*i +j*j;
            if(sum==c){
                return true;
            }else if(sum>c){
                j--;
            }else{
                i++;
            }
        }
        return false;
    }
};