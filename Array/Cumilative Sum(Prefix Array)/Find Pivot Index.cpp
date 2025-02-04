// Appraoch 1: optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int sumR = accumulate(begin(nums), end(nums), 0);
    int sumL = 0;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      sumR -= nums[i];
      if (sumL == sumR) return i;
      sumL += nums[i];
    }
    return -1;
  }
};

// Approach 2: Brute force
// TC: O(2n) -> O(n)
// TC: O(3n) -> O(n)
class Solution {
 public:
  int pivotIndex(vector<int>& nums) {
    int n = nums.size();
    vector<int> leftSum(n), rightSum(n);
    int lSum = 0, rSum = 0;
    for (int i = 0, j = n - 1; i < n; i++, j--) {
      lSum += nums[i], rSum += nums[j];
      leftSum[i] = lSum, rightSum[j] = rSum;
    }
    for (int i = 0; i < n; i++) {
      if ((leftSum[i] - nums[i]) == rightSum[i] - nums[i]) return i;
    }
    return -1;
  }
};
