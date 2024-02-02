class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
    string s="123456789";
    vector<int> ans;
   
    for(int i=2;i<=s.length();i++){
        for(int j=0;j<=s.length()-i;j++){
            string current=s.substr(j,i);
            int pos =stoi(current);
            if(pos>=low && pos<=high) ans.push_back(pos);
        }
    }
    return ans;
        
    }
};