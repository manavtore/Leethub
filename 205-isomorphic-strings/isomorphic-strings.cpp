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

        if(S.find(schar)==S.end()){
            S[schar]=tchar;
        }else if(S[schar]!=tchar){
            return false;
        }

         if(T.find(tchar)==T.end()){
             T[tchar]=schar;
         }else if(T[tchar]!=schar){
             return false;
         }
           
           

    }
     return true;
    }
};

// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if (s.length() != t.length()) {
//             return false;
//         }
//         unordered_map<char, char> S;
//         unordered_map<char, char> T;

//         for (int i = 0; i < s.length(); i++) {
//             char schar = s[i];
//             char tchar = t[i];

//             if (S.find(schar) == S.end()) {
//                 S[schar] = tchar;
//             } else if (S[schar] != tchar) {
//                 return false;
//             }

//             if (T.find(tchar) == T.end()) {
//                 T[tchar] = schar;
//             } else if (T[tchar] != schar) {
//                 return false;
//             }
//         }

//         return true;
//     }
// };
