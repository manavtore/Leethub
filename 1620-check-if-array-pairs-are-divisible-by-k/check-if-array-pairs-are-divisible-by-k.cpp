class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int> count(k,0);

        for(int num:arr){
            int curr = ((num % k) + k) %k;
            count[curr]++;
        }

        for(int i=1;i<k;i++){
            if(count[i] != count[k-i]){
                return false;
            }
        }

        if(count[0]%2!=0){
            return false;
        }
        return true;
    }
};