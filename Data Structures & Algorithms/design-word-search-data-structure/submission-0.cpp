class WordDictionary {
public:
    struct node {
        node* children[26];
        bool isend;
        node() {
            isend = false;
            for (int i = 0; i < 26; i++) children[i] = nullptr;
        }
    };

    node* root;

    WordDictionary() {
        root = new node();
    }
    
    void addWord(string word) {
        node* cur = root;
        for (char& c : word) {
            int idx = c - 'a';
            if (cur->children[idx] == nullptr) cur->children[idx] = new node();
            cur = cur->children[idx];
        }
        cur->isend = true; // FIXED
    }
    
    bool search(string word) {
        return dfs(word, 0, root);
    }

    bool dfs(string& word, int pos, node* root) {
        if (!root) return false;
        if (pos == word.size()) return root->isend; // FIXED

        char c = word[pos];
        if (c == '.') {
            for (int i = 0; i < 26; i++) {
                if (dfs(word, pos+1, root->children[i])) return true;
            }
            return false;
        } else {
            return dfs(word, pos+1, root->children[c - 'a']); // FIXED
        }
    }
};
