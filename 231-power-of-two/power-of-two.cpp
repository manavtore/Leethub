class Solution {
public:
    bool isPowerOfTwo(int n) {
        if(n==1) return true;
    
        long long ans=1;
        while(ans<n){
            ans=ans*2;
            if(ans==(long long)n) return true;
        }
        return false;;
    }
};