// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int n = nums.size();
    int i = 0, j = 1;

    while (j < n) {
      if (nums[i] != nums[j]) {
        nums[++i] = nums[j];  // add unique to next idx
      }
      j++;  // search for unque element
    }
    return i + 1;
  }
};