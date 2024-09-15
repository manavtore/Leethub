class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();

        long long total_chalk = 0;
        for(int i=0;i<n;i++){
            total_chalk += chalk[i];
        }

        k %= total_chalk;

         for (int i = 0; i < n; i++){
            if(k<chalk[i]){
                return i;
            }
            k -= chalk[i];
        }
        return -1;
    }
};