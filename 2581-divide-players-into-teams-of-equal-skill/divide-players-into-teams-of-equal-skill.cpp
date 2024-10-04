class Solution {
public:
    long long dividePlayers(vector<int>& skills) {
        sort(skills.begin(),skills.end());
        int n = skills.size();
        long long chemistrySum = 0;
        int check = skills[0] + skills[n-1];
        for(int i=0;i<n/2;i++){
            int currSum = skills[i] + skills[n-i-1];
            if( currSum != check) return -1;
            chemistrySum += (int) skills[i] * skills[n-i-1];
        }
        return chemistrySum;
    }
};