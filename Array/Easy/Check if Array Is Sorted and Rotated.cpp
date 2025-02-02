// Approach 1:
// SC: O(1)
// TC: O(n)
class Solution {
 public:
  bool check(vector<int>& nums) {
    int n = nums.size();

    int peakCount = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] > nums[(i + 1) % n]) {
        peakCount++;
      }
    }
    return peakCount <= 1;
  }
};

// Approach 2: Brute force
// TC: O(n^2)
// SC: O(1)
class Solution {
 public:
  bool check(vector<int>& nums) {
    int n = nums.size();

    // start from each index and check array is sorted or not
    for (int i = 0; i < n; i++) {
      int cnt = n - 1;
      int j = i;
      bool sorted = true;

      while (cnt--) {
        if (nums[j % n] > nums[(j + 1) % n]) {
          sorted = false;
          break;
        }
        j++;
      }
      if (sorted) return true;
    }
    return false;
  }
};
