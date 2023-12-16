class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.length()!=t.length()) return false;

        unordered_map<char,int> charCount;

          for (char c : s) {
            charCount[c]++;
              }
         for (char c : t) {
            charCount[c]--;
              }
    
          for(const auto& pair:charCount){
              if(pair.second!=0){
                  return false;
              }
          }
       return true;
    }
};