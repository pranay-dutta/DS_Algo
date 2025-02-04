// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int maxAscendingSum(vector<int>& nums) {
    int n = nums.size();
    int maxSum = nums[0];
    int sum = nums[0];

    for (int i = 1; i < n; i++) {
      if (nums[i - 1] >= nums[i]) { //If increasing increase sum
        sum = nums[i];
      } else {
        sum += nums[i]; //else reset the sum
      }
      maxSum = max(sum, maxSum);
    }
    return maxSum;
  }
};