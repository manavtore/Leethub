class Solution {
public:
    int repeatedStringMatch(string a, string b) {
       int times=1;
        string repeated = a;
        while(repeated.find(b)==string::npos && repeated.length()<=2*a.length()+b.length()){
           repeated+=a;
           times++;
       }
     
       return (repeated.find(b)!=string::npos)?times:-1;
       
    }
};