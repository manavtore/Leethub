constexpr int N=5e4, mod=1e9+7;
int qMax[N], qMin[N];
int frontX, backX, frontN, backN;

class Solution {
public:
    static int countPartitions(vector<int>& nums, int k) {
        const int n=nums.size();

        frontX=frontN=0;
        backX=backN=-1;

        long long cnt=0;
        int* sum=(int*)alloca((n+2)*sizeof(int));
        memset(sum, 0, sizeof(sum));
        sum[1]=1;

        for (int l=0, r=0; r< n; r++) {
            int x=nums[r];

            while (backX>=frontX && qMax[backX]<x) backX--;
            qMax[++backX]=x;

            while (backN>=frontN && qMin[backN]>x) backN--;
            qMin[++backN]=x;

            while (qMax[frontX]-qMin[frontN]>k) {
                const int y=nums[l];
                frontX+=(qMax[frontX]==y);
                frontN+=(qMin[frontN]==y);
                l++;
            }

            cnt=(mod+sum[r+1]-sum[l])%mod;
            sum[r+2]=(sum[r+1]+cnt)%mod;
        }
        return cnt;
    }
};