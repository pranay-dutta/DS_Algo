class TrieNode {
  public:
  int isEndOfWord;
  TrieNode* children[26];
  TrieNode() {
    isEndOfWord = 0;
    for(int i = 0; i < 26; i++) {
      children[i] = nullptr;
    }
  }
};

class Trie {
  private:
  TrieNode* root;
  
  public:
  Trie() {
    root = new TrieNode();
  }
  /*Insert a word in Trie*/
  void insert(string word) { //TC: O(word.length())
    TrieNode* crawler = root;
    for(char ch : word) {
      int i = ch - 'a';
      if(crawler->children[i] == nullptr) {
        crawler->children[i] = new TrieNode();
      }
      crawler = crawler->children[i];
    }
  }

  /*Search a word in Trie*/
  bool search(string word) { //TC: O(word.length())
    TrieNode* crawler = root;
    for(char ch : word) {
      int i = ch - 'a';
      if(crawler->children[i] == nullptr) {
        return false;
      }
      crawler = crawler->children[i];
    }
    if (crawler && crawler->isEndOfWord) return true;
    return false;
  }

  /*Search a prefix in Trie*/
  bool startsWith(string prefix) {
    TrieNode* crawler = root;
    for(char ch : word) {
      int i = ch - 'a';
      if(crawler->children[i] == nullptr) {
        return false;
      }
      crawler = crawler->children[i];
    }
    return true;
  }
};
