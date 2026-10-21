
class TrieNode {
public:
    char data;
    bool isTerminal;
    TrieNode* children[26];

    TrieNode(char ch) {
        data = ch;
        isTerminal = false;

        for (int i = 0; i < 26; i++) {
            children[i] = NULL;
        }
    }
};

class Trie {
public:
    TrieNode* root;

    Trie() {
        root = new TrieNode('\0');
    }

    void InsertUtil(TrieNode* root, string word) {
        if (word.length() == 0) {
            root->isTerminal = true;
            return;
        }

        int index = word[0] - 'a';
        TrieNode* child;

        if (root->children[index] != NULL) {
            child = root->children[index];
        } else {
            child = new TrieNode(word[0]);
            root->children[index] = child;
        }

        InsertUtil(child, word.substr(1));
    }

    void InsertWord(string word) {
        InsertUtil(root, word);
    }
};

class Solution {
private:
    void dfs(vector<vector<char>>& board, int i, int j,
             TrieNode* node, string& path,
             vector<string>& ans) {

        int m = board.size();
        int n = board[0].size();

        if (i < 0 || j < 0 || i >= m || j >= n)
            return;

        if (board[i][j] == '#')
            return;

        char ch = board[i][j];
        int index = ch - 'a';
        if (node->children[index] == NULL)
            return;

        node = node->children[index];
        path.push_back(ch);

        if (node->isTerminal) {
            ans.push_back(path);
            node->isTerminal = false;
        }

        board[i][j] = '#';

        dfs(board, i + 1, j, node, path, ans);
        dfs(board, i - 1, j, node, path, ans);
        dfs(board, i, j + 1, node, path, ans);
        dfs(board, i, j - 1, node, path, ans);

        board[i][j] = ch;
        path.pop_back();
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {

        if (board.empty() || board[0].empty())
            return {};

        Trie* t = new Trie();

        for (string word : words) {
            t->InsertWord(word);
        }

        vector<string> ans;
        string path = "";

        int m = board.size();
        int n = board[0].size();

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                dfs(board, i, j, t->root, path, ans);
            }
        }

        return ans;
    }
};
