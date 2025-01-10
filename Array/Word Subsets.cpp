// Approach 1: Optimal
// TC: O(n*(l+26) + m*(l+26)) -> (n*l + m*l) -> (n + m)*l
// SC: O(1)
class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int n = words1.size();
    vector<string> ans;
    int mp[26] = {0};  // SC: O(26)

    for (auto& word2 : words2) {               // O(n)
      int tmp[26] = {0};                       // SC: (26) -> O(1)
      for (auto& w2 : word2) tmp[w2 - 'a']++;  // TC: O(l) //number of letters

      for (int i = 0; i < 26; i++) {  // TC: O(26) -> O(1)
        mp[i] = max(mp[i], tmp[i]);
      }
    }

    for (auto& word1 : words1) {             // TC: O(m)
      int tmp[26] = {0};                     // SC: O(26) -> O(1)
      for (auto& w : word1) tmp[w - 'a']++;  // TC: O(l)

      bool found = 1;
      for (int i = 0; i < 26; i++) {  // TC: O(26) -> O(1)
        if (mp[i] > tmp[i]) {
          found = 0;
          break;
        }
      }
      if (found) ans.push_back(word1);
    }

    return ans;
  }
};
auto init = []() {
  ios::sync_with_stdio(0);
  std::cout.tie(0);
  std::cin.tie(0);
  return '1';
};

// Approach 2;
// TC: O(n*(l*u) + m*(l*u)) -> O(n+m)*l
// SC: O(u+u+n) -> O(n)
class Solution {
 public:
  vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
    int n = words1.size();
    vector<string> ans;
    unordered_map<char, int> mp;  // SC: O(n)

    for (auto& word2 : words2) {         // TC: O(n)
      unordered_map<char, int> tmp;      // SC: O(u)
      for (auto& w2 : word2) tmp[w2]++;  // TC: O(l)

      if (mp.empty())
        mp = tmp;
      else {
        for (auto& p : tmp) {  // TC: O(u) //number of unique letters in current word. ~ O(26)
          auto [ch, freq] = p;
          mp[ch] = max(freq, mp[ch]);
        }
      }
    }

    for (auto& word1 : words1) {     // TC: O(m)
      unordered_map<char, int> tmp;  // SC: O(u)
      bool found = 1;
      for (auto& w : word1) tmp[w]++;  // TC: O(l)

      for (auto& p : mp) {  // TC: O(u) -> ~ O(26)
        auto [ch, freq] = p;
        if (tmp[ch] < freq) {
          found = 0;
          break;
        }
      }

      if (found) ans.push_back(word1);
    }

    return ans;
  }
};
