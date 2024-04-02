class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int n1 = s.length();
        int n2 = t.length();
        if(n1!=n2) return false;
        unordered_map<char,char> forS(n1);
        unordered_map<char,char> forT(n2);

        for(int i=0;i<s.length();i++){
            if(forS.find(s[i])!=forS.end()){
                if(forS[s[i]]!=t[i]){
                    return false;
                }
            }else{
                forS[s[i]]=t[i];
            }
        }
        for(int i=0;i<t.length();i++){
            if(forT.find(t[i])!=forT.end()){
                if(forT[t[i]]!=s[i]){
                    return false;
                }
            }else{
                forT[t[i]]=s[i];
            }
        }
        return true;
    }
};