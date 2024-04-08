class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int n=students.size();
        stack<int> sand;
        queue<int> stud;

        for(int i=0;i<n;i++){
            sand.push(sandwiches[n-1-i]);
            stud.push(students[i]);
        }

        int missing=0;
        while(!sand.empty()){
            if(stud.front()==sand.top()){
                sand.pop();
                stud.pop();
                missing =0;
            }else{
                stud.push(stud.front());
                stud.pop();
                missing++;
                if(missing==n) break;
            }
        }
        return stud.size();
    }
};