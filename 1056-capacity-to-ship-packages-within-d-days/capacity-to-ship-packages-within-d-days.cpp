class Solution {
public:
    int calculateDays(vector<int>& weights,int mid){
        int totalDays=1;
        int sum=0;
        int n=weights.size();
        for(int i=0;i<n;i++){
            sum=sum+weights[i];
            if(sum>mid){
                totalDays++;
                sum=weights[i];
            }
        }
        return totalDays;

    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int high=accumulate(weights.begin(),weights.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            if(calculateDays(weights,mid)<=days){
                high=mid-1;
            }else{
                low=mid+1;
            }
        }
        return low;
    }
};