class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        vector<int> suffix(n);
        vector<int> prefix(n);
        prefix[0]=height[0];
        suffix[n-1]=height[n-1];
        for(int i=1;i<n;i++){
            prefix[i]=max(height[i],prefix[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            suffix[i]=max(height[i],suffix[i+1]);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            ans += min(suffix[i],prefix[i]) - height[i];
        }
        return ans;
    }
};