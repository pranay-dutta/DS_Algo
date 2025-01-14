// Approach 1:
// TC: O(m*n) + k*(m+n) Worst case: O(m*n + m^2 + n^2)
// SC: O(k)
class Solution {
 public:
  void setZeroes(vector<vector<int>>& matrix) {
    vector<pair<int, int>> indices;  // indices where 0 was seen //SC: O(n)
    int m = matrix.size();
    int n = matrix[0].size();

    for (int i = 0; i < m; i++) {                          // row //TC: O(m)
      for (int j = 0; j < n; j++) {                        // col //TC: O(n)
        if (matrix[i][j] == 0) indices.push_back({i, j});  // storing indices
      }
    }

    for (auto& [i, j] : indices) {         // O(k)
      for (int col = 0; col < n; col++) {  // adding zeros to ith row TC: O(n)
        matrix[i][col] = 0;
      }
      for (int row = 0; row < m; row++) {  // adding zeros to jth col TC: O(m)
        matrix[row][j] = 0;
      }
    }
  }
};
