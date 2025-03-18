// Approach 1: Sliding windows
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int n = nums.size();

    int mask = 0, res = 1;
    int i = 0, j = 0;

    while (j < n) {
      while ((mask & nums[j]) != 0) {  // Shink window
        mask = mask ^ nums[i];
        i++;
      }

      res = max(j - i + 1, res);
      mask |= nums[j];
      j++;
    }
    return res;
  }
};

// Approach 2:
// TC: O(n^2)
// SC: O(1)
class Solution {
 public:
  int longestNiceSubarray(vector<int>& nums) {
    int res = 1;
    int n = nums.size();

    for (int i = 0; i < n; i++) {
      int mask = 0;
      for (int j = i; j < n; j++) {
        if ((mask & nums[j])) break;

        mask |= nums[j];
        res = max(j - i + 1, res);
      }
    }
    return res;
  }
};