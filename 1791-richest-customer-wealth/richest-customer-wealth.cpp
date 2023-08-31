class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
       
        int maximum=0;
       
       for(const auto& customer: accounts){
           int sum = accumulate(customer.begin(),customer.end(),0);
           maximum =max(sum,maximum);
       }
       return maximum;
    }
};