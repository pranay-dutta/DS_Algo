// Approach 1:
// TC: O(m*n log(m*n))
// SC: O(2(m*n)) -> O(m*n)
class Solution {
 public:
  vector<vector<int>> directions = { {0, 1}, {0, -1}, {-1, 0}, {1, 0}};  // R L U D
  int trapRainWater(vector<vector<int>>& heightMap) {
    int m = heightMap.size();
    int n = heightMap[0].size();

    priority_queue<vector<int>, vector<vector<int>>, greater<>> boundaryCells;  //{height, i, j} //{height, co-ordinate}
    vector<vector<bool>> visited(m, vector<bool>(n, false));

    // Left boundary and right boundary. ie. (0'th col and n-1'th col)
    for (int i = 0; i < m; i++) {  // TC: O(m)
      for (int j : {0, n - 1}) {   // first and last col only
        boundaryCells.push( {heightMap[i][j], i, j});  // height of current boundary cell
        visited[i][j] = true;
      }
    }

    // Top boundary and bottom boundary. ie. (0'th row and m-1'th row)
    for (int j = 0; j < n; j++) {  // TC: O(n)
      for (int i : {0, m - 1}) {   // first and last row only
        boundaryCells.push( {heightMap[i][j], i, j});  // height of current boundary cell
        visited[i][j] = true;
      }
    }

    int trappedWater = 0;
    while (!boundaryCells.empty()) {  // TC: O(m*n)
      auto currentCell = boundaryCells.top();
      boundaryCells.pop();  // O(log(size of heap))

      int height = currentCell[0];  // height of current cell. ie. heightMap[i][j]
      int i = currentCell[1];
      int j = currentCell[2];

      for (auto& dir : directions) {  // ngbrs of {i,j}
        int i_ = i + dir[0];
        int j_ = j + dir[1];

        if (i_ >= 0 && j_ >= 0 && i_ < m && j_ < n && !visited[i_][j_]) {  // checking if valid cell or not visited
          trappedWater += max(height - heightMap[i_][j_], 0);

          boundaryCells.push({max(height, heightMap[i_][j_]), i_, j_});  // push current cell's into heap

          visited[i_][j_] = true;
        }
      }
    }
    return trappedWater;
  }
};