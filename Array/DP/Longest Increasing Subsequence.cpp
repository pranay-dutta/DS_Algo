// Approach 1: Bottom up aka tabulation
// TC: O(n^2)
// SC: O(n)
class Solution {
 public:
  int lengthOfLIS(vector<int>& nums) {
    // state: t[i] = longest increasing subsequence ending at ith index
    int n = nums.size();
    vector<int> t(n, 1);

    int maxLIS = 0;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
        if (nums[j] < nums[i]) {
          t[i] = max(t[i], t[j] + 1);
        }
      }
      maxLIS = max(maxLIS, t[i]);
    }

    return maxLIS;
  }
};
