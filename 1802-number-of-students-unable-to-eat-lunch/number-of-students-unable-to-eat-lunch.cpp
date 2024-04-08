class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int oneCount=0,zeroCount=0;
        int n=students.size();
        for(auto c:students){
            if(c==0) zeroCount++;
            else oneCount++;
        }

        for(int sand:sandwiches){
            if(sand==0 && zeroCount==0) return oneCount;
            if(sand==1 && oneCount==0) return zeroCount;

            if(sand==0) zeroCount--;
            else oneCount--;
        }
        return 0;
    }
};