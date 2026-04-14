class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* curr = root;

        while (curr) {
            if (curr->left) {
                // Find rightmost node of left subtree
                TreeNode* prev = curr->left;
                while (prev->right) {
                    prev = prev->right;
                }

                // Attach right subtree to the rightmost node
                prev->right = curr->right;

                // Move left subtree to right
                curr->right = curr->left;
                curr->left = NULL;
            }

            // Move to next node
            curr = curr->right;
        }
    }
};