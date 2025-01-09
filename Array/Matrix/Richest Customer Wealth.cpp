// Approach 1:
// TC: O(m * n)
// SC: O(1)
class Solution {
 public:
  int maximumWealth(vector<vector<int>>& accounts) {
    int m = accounts.size();     // row
    int n = accounts[0].size();  // col

    int highestWealth = 0;
    for (int i = 0; i < m; i++) {  // O(n)
      int curCusWealth = 0;
      for (int j = 0; j < n; j++) {  // O(m)
        curCusWealth += accounts[i][j];
      }
      highestWealth = max(highestWealth, curCusWealth);
    }
    return highestWealth;
  }
};