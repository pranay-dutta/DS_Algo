// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int longestMonotonicSubarray(vector<int>& nums) {
    int cSI = 1;  // current strictly increasing
    int cSD = 1;  // current strictly decreasing

    int maxSI = 1, maxSD = 1;
    int n = nums.size();

    for (int i = 0; i < n - 1; i++) {
      if (nums[i] < nums[i + 1]) {
        cSD = 1, cSI++;
      } else if (nums[i] > nums[i + 1]) {
        cSD++, cSI = 1;
      } else {
        cSD = 1, cSI = 1;
      }
      maxSD = max(maxSD, cSD);
      maxSI = max(maxSI, cSI);
    }
    return max(maxSI, maxSD);
  }
};