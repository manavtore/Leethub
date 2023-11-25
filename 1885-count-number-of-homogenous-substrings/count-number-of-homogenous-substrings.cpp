#define ll long long int 
#define MOD 1000000007

class Solution {
public:
    int countHomogenous(string s) {
      ll ans=0;
        for(int i=0;i<s.length();){
            ll count=0;
            char c=s[i];
            while(i<s.length() && s[i]==c){
                count++;
                i++;
            }
            ans+=((count*(count+1))/2)%MOD;
        }
        return (int)ans%MOD;
    }
};