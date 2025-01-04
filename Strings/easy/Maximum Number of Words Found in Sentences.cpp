// TC: O(n*m) //m=longest string
// SC: O(1)
class Solution {
 public:
  int mostWordsFound(vector<string>& sentences) {
    int maxWords = 0;

    for (string sentence : sentences) {
      int spaces = 0;
      for (char c : sentence) {
        if (c == ' ') spaces++;
      }
      maxWords = max(maxWords, spaces + 1); //space+1 means number of words
    }
    return maxWords;
  }
};
