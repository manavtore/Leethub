class Solution {
public:
    int thirdMax(vector<int>& nums) {
      long long firstmax= LLONG_MIN, secondmax = LLONG_MIN, thirdmax = LLONG_MIN;

      for(int num : nums){
       if(num == firstmax || num == secondmax || num == thirdmax ){
           continue;
       }

         if(num > firstmax){
             thirdmax = secondmax;
             secondmax = firstmax;
             firstmax = num;
         }else if(num > secondmax ){
           thirdmax = secondmax;
           secondmax = num;
         }else if(num > thirdmax){
           thirdmax = num;
         }

      }
      return (thirdmax != LLONG_MIN) ? static_cast<int>(thirdmax) : static_cast<int>(firstmax); 
}
};