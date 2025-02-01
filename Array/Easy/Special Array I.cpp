// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  bool isArraySpecial(vector<int>& nums) {
    int last = nums[0] & 1;
    int n = nums.size();
    for (int i = 1; i < n; i++) {
      if (last == (nums[i] & 1)) return false;
      last = nums[i] & 1;
    }
    return true;
  }
};
