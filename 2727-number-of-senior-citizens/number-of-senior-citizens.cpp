class Solution {
public:
    int countSeniors(vector<string>& details) {
        int n = details.size();
        int cnt =0;
        for(int i=0;i<n;i++){
            string s = details[i];
            int age = stoi(s.substr(11,2));
            if(age>60){
                cnt++;
            }
        }
        return cnt;
    }
};