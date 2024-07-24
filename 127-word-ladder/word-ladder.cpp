class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set<string> l(wordList.begin(),wordList.end());
        l.erase(beginWord); 
        q.push({beginWord,1});

        while(!q.empty()){
            string word = q.front().first;
            int step = q.front().second;
            q.pop();
            if(word==endWord) return step;
            for(int i=0;i<word.size();i++){
                char original = word[i];
                for(char ch='a';ch<='z';ch++){
                    word[i]=ch;
                     if(l.find(word) != l.end()){
                        l.erase(word); 
                        q.push({word,step+1});
                  }
                }
                word[i] = original;
            }
            
        }
        return 0;
        
    }
};