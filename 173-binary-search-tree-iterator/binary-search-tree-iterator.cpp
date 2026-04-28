class BSTIterator {
private:
    stack<TreeNode*> st;

    // Push all left nodes
    void pushAllLeft(TreeNode* node) {
        while (node != NULL) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushAllLeft(root);
    }
    
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        
        // If right exists, process it
        if (temp->right != NULL) {
            pushAllLeft(temp->right);
        }
        
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};