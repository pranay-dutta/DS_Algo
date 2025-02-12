// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int digitSum(int n) {  // O(9)
    int x = 0;
    while (n) {
      x += n % 10;
      n /= 10;
    }
    return x;
  }
  int maximumSum(vector<int>& nums) {
    int map[82] = {0};
    int maxSum = 0;

    for (int& num : nums) {  // O(n)
      int sum = digitSum(num);

      if (map[sum]) {
        maxSum = max(maxSum, map[sum] + num);
      }
      map[sum] = max(map[sum], num);
    }

    return maxSum == 0 ? -1 : maxSum;
  }
};
