// Approach 1:
// TC: ~O(n*n)
// SC: O(n * n+1) / 2 -> ~O(n^2)
class Solution {
 public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> T;
    for (int i = 0; i < numRows; i++) {  // O(n)
      vector<int> curRow(i + 1, 1);
      int j = 1;

      while (j < i) {  // starts from 3rd row
        curRow[j] = T[i - 1][j - 1] + T[i - 1][j];
        j++;
      }
      T.push_back(curRow);
    }
    return T;
  }
};
