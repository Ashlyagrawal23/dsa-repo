class Trie {
private:
    struct Node {
        Node* children[26];
        bool isEnd;

        Node() {
            isEnd = false;
            for (int i = 0; i < 26; i++)
                children[i] = NULL;
        }
    };

    Node* root;

public:
    Trie() {
        root = new Node();
    }

    // Insert word into Trie
    void insert(string word) {
        Node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == NULL) {
                node->children[index] = new Node();
            }
            node = node->children[index];
        }
        node->isEnd = true;
    }

    // Search complete word
    bool search(string word) {
        Node* node = root;
        for (char c : word) {
            int index = c - 'a';
            if (node->children[index] == NULL)
                return false;
            node = node->children[index];
        }
        return node->isEnd;
    }

    // Check prefix
    bool startsWith(string prefix) {
        Node* node = root;
        for (char c : prefix) {
            int index = c - 'a';
            if (node->children[index] == NULL)
                return false;
            node = node->children[index];
        }
        return true;
    }
};