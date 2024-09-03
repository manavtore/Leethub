class Solution {
public:
    int getLucky(string s, int k) {
        
        string s1="";

        for(char c:s){
            s1 += to_string(c - 'a' + 1);
        }

        while(k>0){
            int sum = 0;

            for(char c:s1){
                sum += c - '0';
            }

            s1 = to_string(sum);
            k--;
        }
        return stoi(s1);
    }
};