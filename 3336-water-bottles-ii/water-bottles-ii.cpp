class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int emptyBottle = numBottles;
        while(emptyBottle>=numExchange){
            ans++;
            emptyBottle-=numExchange;
            emptyBottle++;
            numExchange++;  
        }
        return ans;
    }
};