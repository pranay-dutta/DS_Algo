// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 private:
  int sqr(int n) { return n * n; }

 public:
  vector<int> sortedSquares(vector<int>& nums) {
    int n = nums.size(), l = 0, r = n - 1;

    vector<int> res(n);
    int endIdx = n - 1;

    /*
      ? Why adding max value at the last ? 
      = As the array sorted in incresing order
      = it's guranteed lowest negative or highest positive will give me
      = highest square.
    */
    for (int i = 0; i < n; i++) {
      int startSq = sqr(nums[l]);
      int endSq = sqr(nums[r]);

      // Gradually add the value to the last
      res[endIdx--] = max(startSq, endSq);
      startSq > endSq ? l++ : r--;
    }
    return res;
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