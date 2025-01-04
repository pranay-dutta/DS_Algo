// Approach 1:
// TC: O(n)
// SC: O(26) -> O(1)
class Solution {
 public:
  bool checkIfPangram(string sentence) {
    bitset<26> bitSet;
    for (char c : sentence) {
      bitSet.set(c - 'a');
    }
    return bitSet.count() == 26;
  }
};

// Approach 2:
// TC: O(n)
// SC: O(26) -> O(1)
class Solution {
 public:
  bool checkIfPangram(string sentence) {
    unordered_set<char> st;
    for (char c : sentence) {
      st.insert(c);
    }
    return st.size() == 26;
  }
};