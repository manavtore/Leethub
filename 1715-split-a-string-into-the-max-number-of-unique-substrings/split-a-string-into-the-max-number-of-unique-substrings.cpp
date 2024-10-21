class Solution {
    int BackTrack(const string& str,int start ,unordered_set<string> unique){
        if(start == str.size()) return unique.size();

        int maxSplit = 0;

        string curr = "";
        for(int i=start;i<str.size();i++){
                curr += str[i];

                if( unique.find(curr) == unique.end() ){

                    unique.insert(curr);

                    int maxCurr = BackTrack(str,i + 1,unique);

                    maxSplit = max(maxSplit,maxCurr);

                    unique.erase(curr);
                }

        }

        return maxSplit;
    }
public:
    int maxUniqueSplit(string s) {
        unordered_set<string> unique;
        return BackTrack(s,0,unique); 
    }

};