// Approach 1:
// TC: O(number of digits) -> O(1) // at worst O(9)
// SC: O(1)
class Solution {
 public:
  int countDigits(int num) {
    int count = 0;
    int temp = num;
    while (temp) {
      int x = temp % 10;  // get the right most digit
      temp /= 10;         // truncate the number from right
      if (num % x == 0) count++;
    }
    return count;
  }
};
