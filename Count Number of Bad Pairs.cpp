//Approach 1: Optimal
// TC: O(n)
// SC: O(n)
class Solution {
 public:
  long long countBadPairs(vector<int>& nums) {
    int n = nums.size();
    long long badPairCnt = 0;

    unordered_map<int, int> seen;  // SC: O(n)
    for (int i = 0; i < n; i++) {  // TC: O(n)
      int diff = nums[i] - i;
      int goodPair = seen[diff];
      int totalPair = i;

      badPairCnt += totalPair - goodPair;
      seen[diff]++;
    }
    return badPairCnt;
  }
};