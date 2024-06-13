class Solution {
public:
    int minMovesToSeat(vector<int>& seats, vector<int>& students) {
        vector<int> seat(*max_element(seats.begin(), seats.end()) + 1, 0);
        vector<int> student(*max_element(students.begin(), students.end()) + 1, 0);

        for(auto el:seats) seat[el]++;
        for(auto el:students) student[el]++;
        int j=0,ans=0;
        for(int i=0;i<seat.size();i++){
            if(seat[i]==0) continue;
            while(student[j]==0) j++;
            ans += abs(i-j);
            student[j]--;
            seat[i]--;
            if(seat[i]!=0) i--; 
        }
        return ans;
    }
};