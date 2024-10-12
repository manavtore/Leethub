class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        vector<int> start;
        vector<int> end;

        for(auto const& pair:intervals){
            start.push_back(pair[0]);
            end.push_back(pair[1]);
        }   

        sort(start.begin(),start.end());
        sort(end.begin(),end.end());

        int i = 0,j=0;
        int group = 0;
        int res = 0;
        while( i< intervals.size()){

            if(start[i]<=end[j]){
                i++;
                group++;
            }else{
                j++;
                group--;
            }
            res = max(res,group);
        }
       
        return res;

    }
};