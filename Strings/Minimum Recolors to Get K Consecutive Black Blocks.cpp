//Approach 1:
//TC: O(n)
//SC: O(1)
class Solution {
 public:
  int minimumRecolors(string blocks, int k) {
    int N = blocks.size();
    int i = 0, j = k;
    int wCnt = 0;

    for (int i = 0; i < j; i++) {
      if (blocks[i] == 'W') wCnt++;
    }
    int minWhites = wCnt;
    while (j < N) {
      if (blocks[i] == 'W') wCnt--;
      if (blocks[j] == 'W') wCnt++;
      if (wCnt == 0) return 0;
      minWhites = min(minWhites, wCnt);
      j++, i++;
    }

    return minWhites;
  }
};