class Solution {
public:
    string sortVowels(string s) {
      string t="";
        for(int i=0;i<s.length();i++){
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' 
            || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||  s[i]=='U' ){
              t+=s[i];
            }
        }
        sort(t.begin(),t.end(),[](char a,char b){ return a<b;});
        int current=0;
        for(int i=0;i<s.length();i++){
            
            if(s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' 
            || s[i]=='A' || s[i]=='E' || s[i]=='I' || s[i]=='O' ||  s[i]=='U' ){
              s[i]=t[current];
              current++;
            }
        }
        return s;
        
    }
};