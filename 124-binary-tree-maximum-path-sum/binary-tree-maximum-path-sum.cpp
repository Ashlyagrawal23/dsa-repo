class Solution {
public:
    int maxSum;

    int solve(TreeNode* root) {
        if (root == NULL) return 0;

        int left = max(0, solve(root->left));
        int right = max(0, solve(root->right));

        // path passing through current node
        int currentPath = root->val + left + right;

        maxSum = max(maxSum, currentPath);

        // return one side path to parent
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        solve(root);
        return maxSum;
    }
};