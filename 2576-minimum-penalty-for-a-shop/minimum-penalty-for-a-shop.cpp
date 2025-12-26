class Solution {
public:
    int bestClosingTime(string customers) {
        int penalty = 0;

        for(char c:customers){
            if( c == 'Y') penalty++;
        }

        int maxpenalty = penalty;
        int bestHour = 0;

        for(int i = 0;i < customers.length();i++){
            if(customers[i]=='Y') penalty--;
            else penalty++;

            if(maxpenalty > penalty){
                maxpenalty = penalty;
                bestHour = i + 1;
            }

        }
        return bestHour;
    }
};