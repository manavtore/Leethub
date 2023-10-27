class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if(s.length()!=t.length()){
            return false;
        }
        unordered_map<char,char> S;
        unordered_map<char,char> T;

        for(int i=0;i<s.length();i++){
          char schar=s[i];
           char tchar=t[i];

        if(S.find(schar)!=S.end()){
            if (S[schar] != tchar) {
                 return false;   
            }
        }else{
            S[schar]=tchar;
        }

         if(T.find(tchar)!=T.end()){
             if(T[tchar] != schar){
                 return false;
             }
         }else{
             T[tchar]=schar;
         }        

    }
     return true;
    }
};

