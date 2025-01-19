// Approach 1:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    int n = nums.size();

    unordered_map<int, int> mp;                             // SC: O(n)
    for (auto it = nums.begin(); it != nums.end(); it++) {  // TC: O(n)
      int complement = target - *it;
      int i = it - nums.begin();
      if (mp.find(complement) != mp.end()) {
        return {i, mp[complement]};
      }
      mp[nums[i]] = i;
    }
    return {};
  }
};

// Approach 2:
// TC: O(n^2)
// SC: O(1)
class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    for (int i = 0; i < nums.size(); i++) {        // O(n)
      for (int j = i + 1; j < nums.size(); j++) {  // O(n)
        if (nums[i] + nums[j] == target) return {i, j};
      }
    }
    return {};
  }
};