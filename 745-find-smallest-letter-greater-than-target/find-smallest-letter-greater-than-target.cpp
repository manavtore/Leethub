class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int diff = INT_MAX;
        char ans = letters[0];

        for(int i=0;i<letters.size();i++){
            int d = letters[i] - target;
            if(d < diff && d> 0){
                ans = letters[i];
                diff = d;
            }
        }
        return ans;
    }
};