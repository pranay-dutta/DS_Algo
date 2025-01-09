// Approach 1: optimal
// TC: O(n * l)
// SC: O(1)
class Solution {
 public:
  int prefixCount(vector<string> &words, string pref) {
    int pz = pref.size();
    int res = 0;
    for (auto &word : words) {           // TC:O(n)
      if (word.substr(0, pz) == pref) {  // TC: O(l)
        res += 1;
      }
    }
    return res;
  }
};
// Approach 2: using Trie
// TC: O(n * l) + p -> O(n*l)
// SC: O(n * l)
class TrieNode {
 public:
  int freq;
  bool isEndOfWord;
  TrieNode *children[26];

  TrieNode() {
    isEndOfWord = false;
    freq = 0;
    memset(children, 0, sizeof(children));
  }
};
class Trie {
 private:
  TrieNode *root;

 public:
  Trie() { root = new TrieNode(); }

  void insert(string &word) {
    TrieNode *crawler = root;
    for (char &ch : word) {
      int i = ch - 'a';
      if (!crawler->children[i]) {
        crawler->children[i] = new TrieNode();
      }
      crawler = crawler->children[i];
      crawler->freq++;
    }
    crawler->isEndOfWord = true;
  }
  bool serach(string &word) {
    TrieNode *crawler = root;
    for (char &ch : word) {
      int i = ch - 'a';
      if (!crawler->children[i]) return false;
      crawler = crawler->children[i];
    }
    if (crawler && crawler->isEndOfWord) return true;
    return false;
  }
  int prefixFreq(string &prefix) {
    TrieNode *crawler = root;
    for (char &ch : prefix) {
      int i = ch - 'a';
      if (!crawler->children[i]) return 0;
      crawler = crawler->children[i];
    }
    return crawler->freq;
  }
  bool startsWith(string &prefix) {
    TrieNode *crawler = root;
    for (char &ch : prefix) {
      int i = ch - 'a';
      if (!crawler->children[i]) return false;
      crawler = crawler->children[i];
    }
    return true;
  }
};
class Solution {
 public:
  int prefixCount(vector<string> &words, string pref) {
    Trie trie;
    for (auto &word : words) {  // O(n)
      trie.insert(word);        // O(l) number of letters
    }
    return trie.prefixFreq(pref);  // O(p)
  }
};
// Approach 3: using unordered map
// TC: O(n * (l^2))
// SC: O(n * (l^2))
class Solution {
 public:
  int prefixCount(vector<string> &words, string pref) {
    unordered_map<string, int> mp;  // SC: O(n * l^2)

    for (auto &word : words) {  // TC:O(n)
      int wz = word.length();
      for (int i = 1; i <= wz; i++) {  // TC: O(l) number of letters
        mp[word.substr(0, i)]++;       // TC: O(l)
      }
    }
    return mp[pref];
  }
};