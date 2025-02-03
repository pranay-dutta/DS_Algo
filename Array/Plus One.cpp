// Approach 1: optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  vector<int> plusOne(vector<int>& digits) {
    int n = digits.size();

    for (int i = n - 1; i >= 0; i--) {
      if (digits[i] == 9) {
        digits[i] = 0;
      } else {
        digits[i] += 1;
        return digits;
      }
    }

    // insert carry if all the numbers were 9
    digits.insert(digits.begin(), 1);
    return digits;
  }
};
