class Solution {
public:
    int romanToInt(string s) {

        unordered_map<char,int> roman={
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };
      int prevalue =0;
      int result =0;

      for(int i=s.length();i>=0;i--){
          int value = roman[s[i]];
          if(value<prevalue){
              result-=value;
          }else{
              result+=value;
          }
          prevalue =value ;
      }
      return result;
        
    }
};