const int al_size = 26;

class TrieNode {
private:
    TrieNode* child[al_size];
    bool fl;

public:
    TrieNode() {
        fl = false;
        for (int i = 0; i < al_size; i++) {
            child[i] = nullptr;
        }
    }

    bool contain(char ch) const {
        return child[ch - 'a'] != nullptr;
    }

    void setChild(char ch, TrieNode* node) {
        child[ch - 'a'] = node;
    }

    TrieNode* getChild(char ch) const {
        return child[ch - 'a'];
    }

    void markEnd() {
        fl = true;
    }

    bool isEnd() const {
        return fl;
    }
};

class Trie {
private:
    TrieNode* root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &s) {
        TrieNode* node = root;
        for (auto i : s) {
            if (!node->contain(i)) {
                node->setChild(i, new TrieNode());
            }
            node = node->getChild(i);
        }
        node->markEnd();
    }

    bool search(const string &s) {
        TrieNode* node = root;
        for (auto i : s) {
            if (!node->contain(i)) {
                return false;
            }
            node = node->getChild(i);
        }
        return node->isEnd();
    }

    bool startWith(const string &s) {
        TrieNode* node = root;
        for (auto i : s) {
            if (!node->contain(i)) {
                return false;
            }
            node = node->getChild(i);
        }
        return true;
    }
};

//  Trie trie;
// trie.insert(s);
