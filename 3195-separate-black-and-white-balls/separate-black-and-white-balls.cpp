class Solution {
public:
    long long minimumSteps(string s) {
        int l = 0;
        long long result = 0;

        for(int i= 0 ; i<s.length() ;){
            if( s[i] == '0'){
                result += ( i - l );
                l++;
            }
            i++;

        }
        return result;
    }
};