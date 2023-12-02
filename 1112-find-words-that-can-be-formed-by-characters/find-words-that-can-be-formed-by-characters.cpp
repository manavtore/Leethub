class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        unordered_map<char,int> charchter;
        int result=0;
        for(char c: chars){
            charchter[c]++;
        }
        
        for(string word: words){
            unordered_map<char,int> wordcount(charchter);
            bool canForm=true;
            for(char c:word){
                if(wordcount.find(c)!=wordcount.end() && wordcount[c]>0){
                    wordcount[c]--;
                }else{
                    canForm=false;
                    break;
                }
            }
             if(canForm){
            result+=word.length();
           }
        }
        return result;
       
        
    }
};