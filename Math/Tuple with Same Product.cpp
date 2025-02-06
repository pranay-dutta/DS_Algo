// Approach 1: Optimal
// TC: O(n^2)
// SC: O(n)
class Solution {
 public:
  int tupleSameProduct(vector<int>& nums) {
    // Frequency of same elemen's whose multiple is same
    unordered_map<int, int> mp;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        int product = nums[i] * nums[j];
        mp[product] += 1;
      }
    }
    // Calculate total permutations for each pair of same product
    int totalPermutations = 0;
    for (auto& [p, f] : mp) {
      // Formula: NC2 = n * (n-1) / 2 {because of 2 number is been chosen}
      if (f >= 2) totalPermutations += 8 * (f * (f - 1) / 2);
    }
    return totalPermutations;
  }
};