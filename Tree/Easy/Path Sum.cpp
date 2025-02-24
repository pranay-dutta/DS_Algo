// Appraoch 1:
// TC: O(n)
// SC: O(n) -system stack
class Solution {
 public:
  bool hasPathSum(TreeNode* root, int targetSum) {
    if (!root) return 0;

    targetSum = targetSum - root->val;
    if (targetSum == 0 && !root->left && !root->right) return true;  // if it's a leaf node only

    bool found = false;
    found |= hasPathSum(root->left, targetSum);
    found |= hasPathSum(root->right, targetSum);

    return found;
  }
};