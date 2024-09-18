class Solution {
public:
    string largestNumber(vector<int>& nums) {
        
        vector<string> str_num;

        for(auto num:nums){
            str_num.push_back(to_string(num));
        }

        sort(str_num.begin(),str_num.end(),[](string& a,string& b){
            return a+b>b+a;
        });

        if(str_num[0]=="0") return "0";
        
        string finalstr = "";
        for(auto str:str_num){
            finalstr +=str;
        }
        return finalstr;
    }
};