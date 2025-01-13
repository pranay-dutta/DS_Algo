// Approach 1: Two pointer
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size();
    int start = 0;
    int end = n - 1;
    vector<int> squareNums(n);

    for (int i = 0; i < n; i++) {
      int startSq = nums[start] * nums[start];
      int endSq = nums[end] * nums[end];

      if (startSq > endSq) {
        ++start;
        squareNums[n - i - 1] = startSq;
      } else {
        --end;
        squareNums[n - i - 1] = endSq;
      }
    }
    return squareNums;
  }
};

// Approach 2:
// TC: O(n^2 + n) -> ~O(n^2)
// SC: O(1) input should not be modified

class Solution {
 public:
  int square(int& n) { return n * n; }
  vector<int> sortedSquares(vector<int>& nums) {
    // Bubble sort
    int n = nums.size();
    for (int i = 0; i < n - 1; i++) {    // O(n)
      for (int j = i + 1; j < n; j++) {  // O(n)
        if (square(nums[i]) > square(nums[j])) {
          int t = nums[j];
          nums[j] = nums[i];
          nums[i] = t;
        }
      }
    }
    for (int i = 0; i < n; i++) {
      nums[i] = square(nums[i]);
    }
    return nums;
  }
};