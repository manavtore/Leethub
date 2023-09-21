class Solution {
public:
    bool isValid(string s) {
        stack<char> bracket;
       for(char c :s ){
         if(c=='(' || c=='[' || c=='{' ){
           bracket.push(c);
         }else if(c==')' || c==']' || c=='}'){
           if(bracket.empty()){
             return false;
           }
             char stacktop= bracket.top();
             bracket.pop();
           if(c==')' &&  stacktop!='(' || c==']' && stacktop!='[' || c=='}' &&   stacktop!='{'){
             return false;
           }
         }
       }
       return bracket.empty();
    }
};