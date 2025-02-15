// Brute force
// TC:
// SC:
class Solution {
 public:
  bool isPunishableNumber(int i, int sum, string& numStr, int target,
                          vector<vector<int>>& t) {
    if (i == numStr.length()) return sum == target;
    if (sum > target) return false;
    if (t[i][sum] != -1) return t[i][sum];

    bool possible = false;
    for (int j = i; j < numStr.length(); j++) {
      string sub = numStr.substr(i, j - i + 1);  //[i..j....] from i to j
      int x = stoi(sub);

      possible |= isPunishableNumber(j + 1, sum + x, numStr, target, t);
      if (possible) return possible;
    }
    return t[i][sum] = possible;
  }

  int punishmentNumber(int n) {
    int punish = 0;
    for (int num = 1; num <= n; num++) {
      int sq = num * num;
      string numStr = to_string(sq);

      vector<vector<int>> t(numStr.length(), vector<int>(num + 1, -1));
      if (isPunishableNumber(0, 0, numStr, num, t)) {
        punish += sq;
      }
    }
    return punish;
  }
};
