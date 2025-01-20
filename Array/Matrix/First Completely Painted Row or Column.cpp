// Approach 1: Optimal
// TC: O(m*n)
// SC: O(2m*n) -> O(m*n)
class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    int m = mat.size();
    int n = mat[0].size();

    int az = arr.size();
    unordered_map<int, int> mp;  // O(m*n)
    for (int i = 0; i < az; i++) {
      mp[arr[i]] = i;
    }

    // Traversing rows
    int minIdx = INT_MAX;
    for (int i = 0; i < m; i++) {  // O(m*n)
      int highestIdxRow = -1;
      for (int j = 0; j < n; j++) {
        highestIdxRow = max(highestIdxRow, mp[mat[i][j]]);
      }
      minIdx = min(highestIdxRow, minIdx);
    }

    // Traversing cols
    for (int j = 0; j < n; j++) {  // O(m*n)
      int highestIdxCol = -1;
      for (int i = 0; i < m; i++) {
        highestIdxCol = max(highestIdxCol, mp[mat[i][j]]);
      }
      minIdx = min(highestIdxCol, minIdx);
    }
    return minIdx;
  }
};

// Approach 2:
// TC: O(m*n + k) -> O(m*n)
// SC: O(2m*n) -> O(m*n)
class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, pair<int, int>> coordinate;  // SC: O(m*n)

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        coordinate[mat[i][j]] = {i, j};
      }
    }

    vector<int> rowFreq(m, 0);  // SC: O(m)
    vector<int> colFreq(n, 0);  // SC: O(n)

    int az = arr.size();
    for (int k = 0; k < az; k++) {  // TC: O(k)
      auto [i, j] = coordinate[arr[k]];

      if (++rowFreq[i] == n || ++colFreq[j] == m) {
        return k;
      }
    }
    return 0;
  }
};

// Approach 3:
// TC: O(m*n + k) -> O(m*n)
// SC: O(m*n + k) -> O(m*n)
class Solution {
 public:
  int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
    unordered_map<int, pair<int, int>> coordinate;  // SC: O(m*n)
    unordered_map<string, int> rowColFreq;          // SC: O(k)

    int m = mat.size();
    int n = mat[0].size();

    for (int i = 0; i < m; i++) {  // TC: O(m*n)
      for (int j = 0; j < n; j++) {
        coordinate[mat[i][j]] = {i, j};
      }
    }

    int az = arr.size();
    for (int k = 0; k < az; k++) {  // TC: O(k)
      auto [i, j] = coordinate[arr[k]];

      string i_ = "r" + to_string(i);
      string j_ = "c" + to_string(j);

      if (++rowColFreq[i_] == n ||
          ++rowColFreq[j_] == m) {  // if row or column fully painted return k'th index
        return k;
      }
    }
    return 0;
  }
};