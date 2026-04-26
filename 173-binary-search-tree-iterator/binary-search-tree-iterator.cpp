class BSTIterator {
public:
    stack<TreeNode*> st;

    // Push all left nodes
    void pushAll(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

    BSTIterator(TreeNode* root) {
        pushAll(root);
    }

    int next() {
        TreeNode* node = st.top();
        st.pop();

        // If right exists, push its left chain
        pushAll(node->right);

        return node->val;
    }

    bool hasNext() {
        return !st.empty();
    }
};