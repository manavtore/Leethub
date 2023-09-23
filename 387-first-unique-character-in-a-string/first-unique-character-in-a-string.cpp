class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,int> charcount;
        for(char c:s){
           charcount[c]++;
        }
        for(int i=0;i<s.length();i++){
            if(charcount[s[i]]==1){
                return i;
            }
        }
        return -1;
    }
};