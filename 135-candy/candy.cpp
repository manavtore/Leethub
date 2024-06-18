class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if (n == 0) return 0;
        vector<int> right(n);
        vector<int> left(n);
        left[0]=1;
        right[n-1]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                right[i]=right[i+1]+1;
            }else{
                right[i]=1;
            }
        }
        int cnt =0;
        for(int i=0;i<n;i++){
            cnt=cnt + max(right[i],left[i]);
        }
        return cnt;

    }
};