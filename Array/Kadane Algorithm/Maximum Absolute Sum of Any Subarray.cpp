// Approach 1: Kadane's Algo
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int maxAbsoluteSum(vector<int>& nums) {
    int n = nums.size();

    //Finding max of subarray sum
    int curSum = nums[0], maxSum = nums[0];
    for (int i = 1; i < n; i++) {
      curSum = max(nums[i], curSum + nums[i]);
      maxSum = max(curSum, maxSum);
    }

    curSum = nums[0];
    int minSum = nums[0];
    //Finding min of subarray sum
    for (int i = 1; i < n; i++) {
      curSum = min(nums[i], curSum + nums[i]);
      minSum = min(curSum, minSum);
    }
    return max(abs(minSum), abs(maxSum));
  }
};