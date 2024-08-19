class Solution {
public:

    int minSteps(int n) {
        
        int ans = 0;
        int dis = 2;

        while(n > 1)
        {
            while(n%dis == 0)
            {
                ans += dis;
                n /= dis;
            } 
            dis++;
        }
        return ans;
    }
};