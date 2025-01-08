// Appraoch 2: Using Trie
// TC: O(n * (3l + (n*l))) -> O(n * (n*l)) -> ~ O(n^2 * l)
// SC: O(n^2 * l)
class TrieNode {
 public:
  bool isEndOfWord;
  vector<TrieNode*> children;
  TrieNode() {
    isEndOfWord = false;
    children = vector<TrieNode*>(26, nullptr);
  }
};

class Trie {
 public:
  TrieNode* root;
  Trie() {
    root = new TrieNode();  // intialize root TrieNode when creating a Trie
  }
  void insert(string& word) {
    TrieNode* crawler = root;  // will crawl to construct the word in the Trie
    for (char& ch : word) {
      int i = ch - 'a';
      if (crawler->children[i] == nullptr) {
        crawler->children[i] = new TrieNode();
      }
      crawler = crawler->children[i];  // move to next character
    }
    crawler->isEndOfWord = true;
  }
  bool startsWith(string& prefix) {
    TrieNode* crawler = root;
    for (char ch : prefix) {
      int i = ch - 'a';  // get the index of current char [a:0, b:1 ....... z:25]
      if (!crawler->children[i]) return false;
      crawler = crawler->children[i];
    }
    return true;
  }
};
class Solution {
 public:
  int countPrefixSuffixPairs(vector<string>& words) {
    int n = words.size();
    int res = 0;

    for (int j = 0; j < n; j++) {  // O(n)
      Trie prefixTrie;
      Trie suffixTrie;

      prefixTrie.insert(words[j]);  // O(l) length of word
      string reversed = words[j];
      reverse(begin(reversed), end(reversed));  // TC: O(l)

      suffixTrie.insert(reversed);  // O(l)

      for (int i = 0; i < j; i++) {  // O(n)
        if (words[i].length() > words[j].length()) continue;

        string rev = words[i];
        reverse(begin(rev), end(rev));  // O(l)

        if (prefixTrie.startsWith(words[i]) && suffixTrie.startsWith(rev)) res++;  // O(l)
      }
    }
    return res;
  }
};
