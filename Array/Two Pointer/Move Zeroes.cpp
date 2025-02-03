// Apporach 1: optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    const int n = nums.size();
    int insIdx = 0;
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        swap(nums[i], nums[insIdx]);
        insIdx++;
      }
    }
  }
};

// Apporach 2: optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    const int n = nums.size();
    int insIdx = 0, zeroCnt = 0;

    // swap numbers to the left
    for (int i = 0; i < n; i++) {
      if (nums[i] != 0) {
        nums[insIdx] = nums[i];
        insIdx++;
      }
    }

    // now put the zeros
    while (insIdx < nums.size()) {
      nums[insIdx++] = 0;
    }
  }
};

// Approach 3: Brute force
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  void moveZeroes(vector<int>& nums) {
    vector<int> nonZeros;
    const int n = nums.size();
    int zeros = 0;
    for (const int& x : nums) {
      if (x == 0)
        zeros++;
      else
        nonZeros.push_back(x);
    }

    for (int i = n - 1; i >= 0; i--) {
      if (zeros > 0) {
        nums[i] = 0;
        zeros--;
      } else {
        nums[i] = nonZeros.back();
        nonZeros.pop_back();
      }
    }
  }
};
