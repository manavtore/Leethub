class Solution {
public:
    int candy(vector<int>& ratings) {
        int n=ratings.size();
        if (n == 0) return 0;
        vector<int> left(n);
        left[0]=1;
        for(int i=1;i<n;i++){
            if(ratings[i]>ratings[i-1]){
                left[i]=left[i-1]+1;
            }else{
                left[i]=1;
            }
        }
        int cnt = max(1,left[n-1]);
        int right = 1;
        int curr=1;
        for(int i=n-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                curr = right+1;
                
            }else{
                curr=1;
            }
            right = curr;
            cnt += max(left[i],curr);
        }
        
        return cnt;

    }
};