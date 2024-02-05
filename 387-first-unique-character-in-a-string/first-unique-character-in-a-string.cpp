class Solution {
public:
    int firstUniqChar(string s) {
        int freq[26]={0};
        for(int i=1;i<=s.length();i++){
            char c=s[i-1]-'a';
            if(freq[c]==0){
                freq[c]=-i;
            }else{
                freq[c]=i;
            }
        }
        int minPosition=INT_MAX;
        for(int i=0;i<26;i++){
            if(freq[i]<0){
                minPosition=min(minPosition,-freq[i]);
            }
        }
        return minPosition==INT_MAX?-1:minPosition-1;
    }
};