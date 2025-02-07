// Approach 1: optimal
// TC: O(Q)
// SC: O(Q^2)
class Solution {
 public:
  vector<int> queryResults(int limit, vector<vector<int>>& queries) {
    // Space: O(Q^2)
    unordered_map<int, int> colorFreq;//{color, freq}                  //SC: O(Q)
    unordered_map<int, int> balls;    //{ball, cur color of i'th ball} //SC: O(Q)
    vector<int> res;                  // Not considering the result O(1)

    for (const auto& query : queries) {  // O(Q)
      int ball = query[0], curColor = query[1];

      if (balls[ball] != 0) {  // if already a colored ball
        int prevColor = balls[ball];
        colorFreq[prevColor] -= 1;

        if (colorFreq[prevColor] == 0) {
          colorFreq.erase(prevColor);
        }
      }
      colorFreq[curColor]++;   // update the freq of color
      balls[ball] = curColor;  // update the color at postion
      res.push_back(colorFreq.size());
    }
    return res;
  }
};