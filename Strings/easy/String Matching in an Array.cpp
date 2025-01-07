// Approach 1:
// TC: O((n*n) * (n+m)) -> O(n^2 * (n+m))
// SC: O(m) //LPS array
class Solution {
 public:
  // longest prefix that is also a suffix
  vector<int> computeLPS(string &text) {
    int m = text.length();
    vector<int> LPS(m);
    LPS[0] = 0;

    for (int i = 1; i < m; i++) {
      int len = LPS[i - 1];

      while (len > 0 && text[i] != text[len]) {
        len = LPS[len - 1];
      }

      if (text[i] == text[len]) len++;  // found len sized LPS
      LPS[i] = len;
    }
    return LPS;
  }

  int KMP(string &pattern, string &text, vector<int> &LPS) {
    int n = pattern.size();
    int m = text.length();
    int i = 0;
    int j = 0;
    while (i < n) {
      if (pattern[i] == text[j]) {
        i++;
        j++;
      } else if (j != 0) {
        j = LPS[j - 1];
      } else {
        i++;  // j can't go -1
      }

      // tex found in pattern
      if (j == m) return (i - j);
    }
    return -1;  // not found text in pattern so return -1 index
  }
  vector<string> stringMatching(vector<string> &words) {
    int n = words.size();
    vector<string> res;

    for (int i = 0; i < n; i++) {  // O(n)
      vector<int> LPS = computeLPS(words[i]);

      for (int j = 0; j < n; j++) {                          // O(n)
        if (j != i && KMP(words[j], words[i], LPS) != -1) {  // O(n+m)
          res.push_back(words[i]);
          break;
        }
      }
    }
    return res;
  }
};
// Approach 2:
// TC: O(n*n*m) -> O(n^2*m)
// SC: O(1)
class Solution {
 public:
  vector<string> stringMatching(vector<string> &words) {
    vector<string> res;
    int n = words.size();

    for (int i = 0; i < n; i++) {    // O(n)
      for (int j = 0; j < n; j++) {  // O(n)

        if (i != j && words[j].find(words[i]) != -1) {  // O(m)
          res.push_back(words[i]);
          break;
        }
      }
    }
    return res;
  }
};
// Approach 1:
// TC: O(n+(n*n*k)) -> O(n + (n^2 + k)) -> (n^2 * k dominates n) -> O(n^2*k)
// SC: O(n)
class Solution {
 public:
  vector<string> stringMatching(vector<string> &words) {
    unordered_set<string> st;           // SC: O(n)
    for (const string &word : words) {  // TC: O(n)
      st.insert(word);
    }

    vector<string> res;
    for (const string &s : st) {  // TC: O(n) n unique element at worst case
      int found = 0;
      for (const string &word : words) {     // TC: O(n)
        if (word.find(s) != string::npos) {  // TC: O(k)
          found++;
        }
        if (found == 2) {
          res.push_back(s);
          break;
        }
      }
    }
    return res;
  }
};