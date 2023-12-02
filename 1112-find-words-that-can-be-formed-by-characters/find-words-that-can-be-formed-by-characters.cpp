class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charcount(26,0);
        int result=0;
        for(char c: chars){
            charcount[c-'a']++;
        }
        for(const string& word: words ){
             vector<int> tempCharCount = charcount;
            bool goodWord = true;
             for(char c: word){
                 if(--tempCharCount[c-'a']<0){
                     goodWord=false;
                     break;
                 }
             }
             if(goodWord){
                result+=word.length();
             }
             
        }
        
       
        return result;
       
        
    }
};