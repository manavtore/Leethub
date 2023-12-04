class Solution {
public:
   string largestGoodInteger(string num) {
    int i = num.length();
    string result = "";

    for(int i=1;i<num.length()-1;i++){
        string current="";
       if(num[i]==num[i-1] && num[i]==num[i+1]){
          current =num.substr(i-1,3);
            if (current.length() > result.length() || (current.length() == result.length() && current > result)) {
                    result = current;
                }
       }
       
    }

    return result;
}

};