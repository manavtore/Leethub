class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        if(n<3)return 0 ;
        int i=1;
        int j=n-2;
        int maxleft = height[0];
        int maxright = height[n-1];
        int ans=0;
        while(i<=j){
            if(maxleft < maxright){
                if(height[i]>=maxleft){
                    maxleft = height[i];
                }else{
                    ans += maxleft - height[i];
                }
                i++;
            }else{
                if(height[j]>=maxright){
                    maxright = height[j];
                }else{
                    ans += maxright - height[j];
                }
                j--;
            }
        }
        return ans;
    }
};