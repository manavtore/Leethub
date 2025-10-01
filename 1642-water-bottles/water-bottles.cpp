class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int drank = numBottles;  
        int empty = numBottles;  
        
        while (empty >= numExchange) {
            int newBottles = empty / numExchange;  
            drank += newBottles;                 
            empty = empty % numExchange + newBottles;  
        }
        
        return drank;
    }
};
