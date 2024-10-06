class Solution {
public:
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> words1 = split(sentence1);
        vector<string> words2 = split(sentence2);
        
        int n1 = words1.size();
        int n2 = words2.size();
        
        if (n1 < n2) {
            swap(words1, words2);
            swap(n1, n2);
        }
        
        int i = 0; 
        int j = 0; 
        

        while (i < n2 && words1[i] == words2[i]) {
            i++;
        }
        

        while (j < n2 && words1[n1 - 1 - j] == words2[n2 - 1 - j]) {
            j++;
        }
  
        return (i + j) >= n2;
    }

private:
    vector<string> split(const string& sentence) {
        istringstream stream(sentence);
        string word;
        vector<string> words;
        while (stream >> word) {
            words.push_back(word);
        }
        return words;
    }
};
