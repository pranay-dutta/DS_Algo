class Solution {
 public:
  int n;
  TreeNode* solve(string& s, int& i, int depth) {
    if (i >= n) return nullptr;

    int j = i;
    while (j < n && s[j] == '-') j++;  // count number of dash

    int dash = j - i;
    if (dash != depth) return nullptr;

    i = j;  // move i to j'th index

    int num = 0;  // Form digit
    while (i < n && isdigit(s[i])) num = (num * 10) + (s[i++] - '0');

    TreeNode* root = new TreeNode(num);
    root->left = solve(s, i, depth + 1);
    root->right = solve(s, i, depth + 1);

    return root;
  }
  TreeNode* recoverFromPreorder(string s) {
    n = s.size();
    int i = 0, depth = 0;
    return solve(s, i, 0);
  };
};
