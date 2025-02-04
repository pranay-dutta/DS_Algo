// Approach 1: Optimal
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int freq = 0;
    int elem = 0;

    /*
     If any elem is coming for more than n/2 times.
     Then no elem can make his frequency to zero
    */
    for (int i = 0; i < nums.size(); i++) {
      if (freq == 0) {
        elem = nums[i];
        freq++;
      } else if (nums[i] == elem) {
        freq++;
      } else {  // if new elem reduce frequency
        freq--;
      }
    }
    return elem;
  }
};

// Approach 2:
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  int majorityElement(vector<int>& nums) {
    int n = nums.size();
    unordered_map<int, int> mp;  // SC: O(n)

    for (int x : nums) mp[x]++;  // TC: O(n)

    for (auto& pair : mp) {  // TC: O(n)
      if (mp[pair.first] > n / 2) return pair.first;
    }
    return -1;
  }
};