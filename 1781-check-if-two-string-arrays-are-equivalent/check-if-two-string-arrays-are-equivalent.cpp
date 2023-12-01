class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string word1str=" ";
        for(auto str: word1){
            word1str+=str;
        }
        string word2str=" ";
        for(auto str: word2){
            word2str+=str;
        }
        return word1str==word2str;

    }
};