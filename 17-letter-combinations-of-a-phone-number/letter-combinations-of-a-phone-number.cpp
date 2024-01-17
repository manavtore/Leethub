class Solution {
public:
    void generateCombo(string digits,unordered_map<char,vector<char>>& pn,vector<string>& ans,string current,int index){

        if(index==digits.length()){
            ans.push_back(current);
            return;
        }
        char digit=digits[index];
        vector<char> letters=pn[digit];

        for(char letter:letters){
            generateCombo(digits,pn,ans,current+letter,index+1);
        }

    }
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        unordered_map<char,vector<char>> pn={
            {'2',{'a','b','c'}},
            {'3',{'d','e','f'}},
            {'4',{'g','h','i'}},
            {'5',{'j','k','l'}},
            {'6',{'m','n','o'}},
            {'7',{'p','q','r','s'}},
            {'8',{'t','u','v'}},
            {'9',{'w','x','y','z'}}
        };
        if(!digits.empty()){
            generateCombo(digits,pn,ans,"",0);
        }
        return ans;
    }
};