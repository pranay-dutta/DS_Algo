// Approach 1:
// TC: O(n)
// SC: O(1)
class Solution {
 public:
  long long gridGame(vector<vector<int>>& grid) {
    long long firstRowRemainSum = accumulate(begin(grid[0]), end(grid[0]), 0LL);
    long long secondRowRemainSum = 0;

    int n = grid[0].size();

    long long minimizedRobot2Sum = LONG_LONG_MAX;
    for (int i = 0; i < n; i++) {  // TC: O(n)
      firstRowRemainSum -= grid[0][i];

      long long currentBestForRobot2 = max( firstRowRemainSum, secondRowRemainSum);  // maximizing robot 2's point

      minimizedRobot2Sum = min(minimizedRobot2Sum, currentBestForRobot2);  // minimized result robot2's move

      secondRowRemainSum += grid[1][i];
    }
    return minimizedRobot2Sum;
  }
};
