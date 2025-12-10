const int M=100001;
int freq[M]={0};
long long Prev[M]={0};
const int mod=1e9+7;

class Solution {
public:
    int specialTriplets(vector<int>& nums) {
        const int n=nums.size();
        memset(freq, 0, sizeof(freq));
        memset(Prev, 0, sizeof(Prev));
        long long cnt=0;

        freq[nums[0]]++;

        int x1=nums[1], x1_2=x1<<1;
        if (x1_2<M) Prev[x1]+=freq[x1_2];
        freq[x1]++;

        for (int i=2; i < n; i++) {
            int x=nums[i], x2=x<<1;

            cnt+=(-((x&1)==0) & Prev[x>>1]);

            if (x2<M) Prev[x]+=freq[x2];

            freq[x]++;
        }

        return cnt%mod;
    }
};