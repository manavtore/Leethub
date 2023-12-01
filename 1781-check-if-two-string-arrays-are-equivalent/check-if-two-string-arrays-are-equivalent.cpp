class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i=0,m=0;
        int j=0,n=0;

        while(i<word1.size() && j<word2.size()){
            if(word1[i][m++]!=word2[j][n++]){
                return false;
            }

            if(m>=word1[i].size()){
                m=0;
                i++;
            }
            if(n>=word2[j].size()){
                n=0;
                j++;
            }


        }
        return i==word1.size() && j==word2.size();

    }
};