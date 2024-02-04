class Solution {
public:
    int minimumTimeToInitialState(string word, int k) {
        int n=word.length();
       for(int i=k;i<word.length();i+=k){
           if(word.substr(0,n-i)==word.substr(i,n-i)){
               return i/k;
           }
       }
       return (n+k-1)/k;
    }
};