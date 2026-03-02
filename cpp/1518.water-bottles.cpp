#include "leetcode.h"

class Solution {
   public:
    int numWaterBottles(int numBottles, int numExchange) {
        int sum = 0;
        
        while (numBottles >= numExchange) {
            sum += numExchange;
            numBottles -= numExchange;

            numBottles++;
        }   

        return sum + numBottles;
    }
};
