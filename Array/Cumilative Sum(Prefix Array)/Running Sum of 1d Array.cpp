// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  vector<int> runningSum(vector<int>& nums) {
    int sum = nums[0];
    int n = nums.size();

    for (int i = 1; i < n; i++) {
      sum += nums[i];
      nums[i] = sum;
    }
    return nums;
  }
};
