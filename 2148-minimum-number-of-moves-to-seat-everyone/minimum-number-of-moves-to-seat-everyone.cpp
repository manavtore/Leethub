class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        sort(seats.begin(),seats.end());
        sort(students.begin(),students.end());
        int move =0;
        for(int i=0;i<students.size();i++){
            if(seats[i]!=students[i]){
                move +=abs(seats[i]-students[i]);
            }
        }
        return move;
    }
};