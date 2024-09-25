class TrieNode{
    public:
    TrieNode* children[26] = {0};
    int count = 0;
};

class Trie{
    public:
     TrieNode* root;
    
     Trie() {
        root = new TrieNode();
     }

     void insert(const string& word){
        TrieNode* node = root;
        for(char c:word){
            int idx = c - 'a';
            if(!node->children[idx]){
                node->children[idx]=new TrieNode;
            }
            node = node->children[idx];
            node->count++;
        }
     }

     int getPrefixScore(const string& word){
        TrieNode* node = root;
        int score = 0;
        for(char c:word){
            int idx = c - 'a';
            if(node ->children[idx]){
                node = node->children[idx];
                score += node->count;
            }
        }
        return score;
     }
};

class Solution {
    public:
    vector<int> sumPrefixScores(vector<string>& words) {
        Trie trie;

        for(const string& word:words){
            trie.insert(word);
        }
        vector<int> result;

        for(const string& word:words){
            int score = trie.getPrefixScore(word);
            result.push_back(score);
        }
        return result;
    }
};