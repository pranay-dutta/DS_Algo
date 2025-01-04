// Approach 1:
// TC: O(n + m*n) -> O(n + 26*n) -> O(2n) -> O(n)
// SC: O(26+26+26)-> O(1)
class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    int n = s.length();
    unordered_set<char> st;
    vector<pair<int, int>> idxs( 26, {-1, -1});  // starting and ending index of every char

    for (int i = 0; i < n; i++) {  // TC: O(n)
      st.insert(s[i]);             // push unique character only

      if (idxs[s[i] - 'a'].first == -1) {
        idxs[s[i] - 'a'] = {i, i};  // starting and ending index
      } else {
        idxs[s[i] - 'a'] = {idxs[s[i] - 'a'].first, i};  // update ending index only
      }
    }

    int ans = 0;
    for (auto t : st) {  // TC: O(m)
      auto [startIdx, endIdx] = idxs[t - 'a'];

      unordered_set<char> visited;
      if (startIdx != endIdx) {  // O(n)
        for (int i = startIdx + 1; i < endIdx; i++) {
          if (!visited.count(s[i])) {  // if not counted already
            visited.insert(s[i]);
          }
        }
      }
      ans += visited.size();
    }
    return ans;
  }
};
// Approach 2:
// O(26* 2n) -> o(n)
// O(26) -> O(1)
class Solution {
 public:
  int countPalindromicSubsequence(string s) {
    bitset<26> exist;
    int ans = 0;
    for (int i = 0; i < 26; i++) {
      int leftIdx = s.find('a' + i);

      if (leftIdx != string::npos) {      // if first index found
        int rightIdx = s.rfind('a' + i);  // find reverse index
        if (rightIdx - leftIdx < 2) continue;  // if firast and last index have no character in between

        for (int k = leftIdx + 1; k < rightIdx; k++) {
          exist.set(s[k] - 'a');  // set that bit
          if (exist.count() == 26) break;  // if all the bits are set {good optimization}
        }
        ans += exist.count();
        exist.reset();  // rest bucket
      }
    }
    return ans;
  }
};
