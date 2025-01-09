// Approach 1:
// TC: O(n * w)
// SC: O(1)
class Solution {
 public:
  vector<int> findWordsContaining(vector<string>& words, char x) {
    int n = words.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) {        // O(n)
      for (const char& ch : words[i]) {  // O(w) //w = word.length()
        if (ch == x) {
          ans.push_back(i);
          break;
        }
      }
    }
    return ans;
  }
};
