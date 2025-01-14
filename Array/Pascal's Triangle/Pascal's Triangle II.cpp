// Approach 1:
// TC: O(n^2)
// SC: O(n)
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> T(1);              // SC: O(1)
    for (int i = 0; i <= rowIndex; i++) {  // TC: O(n)
      vector<int> curRow(i + 1, 1);        // SC: O(n)
      int j = 1;

      while (j < i) {  // TC: O(n)-2
        curRow[j++] = T[0][j - 1] + T[0][j];
      }
      T[0] = curRow;
    }
    return T[0];
  }
};

// Approach 2:
// TC: O(n^2)
// SC: O(n^2)
class Solution {
 public:
  vector<int> getRow(int rowIndex) {
    vector<vector<int>> Triangle;          // SC: O(n)
    for (int i = 0; i <= rowIndex; i++) {  // TC: O(n)
      vector<int> curRow(i + 1, 1);        // SC: O(n)
      int j = 1;
      while (j < i) {  // TC: O(n)
        curRow[j] = Triangle[i - 1][j - 1] + Triangle[i - 1][j];
        j++;
      }
      Triangle.push_back(curRow);
    }
    return Triangle[rowIndex];
  }
};