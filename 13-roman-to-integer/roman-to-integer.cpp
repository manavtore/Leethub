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
        int result=0;
        int prevalue=0;

        for(char c:s){
            int value=roman[c];
            result+=(value>prevalue)?(value-2*prevalue):value;
            prevalue=value;
        }
        return result;
        
    }
};