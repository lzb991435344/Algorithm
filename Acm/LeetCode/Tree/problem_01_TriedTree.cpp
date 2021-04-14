

/*leetcode 208
Input
    ["Trie", "insert", "search", "search", "startsWith", "insert", "search"]
    [[], ["apple"], ["apple"], ["app"], ["app"], ["app"], ["app"]]
Output
    [null, null, true, false, true, null, true]

    Explanation
    Trie trie = new Trie();
    trie.insert("apple");
    trie.search("apple");   // return True
    trie.search("app");     // return False
    trie.startsWith("app"); // return True
    trie.insert("app");
    trie.search("app");     // return True

*/

class Trie {
public:
    /** Initialize your data structure here. */
    struct TriedTreeNode{
        bool flag;
        TriedTreeNode* childrens[26] = {nullptr};
        TriedTreeNode():flag(false){
        }
    };
    struct TriedTreeNode* root;
    Trie() {
        root = new TriedTreeNode();
    }
    /** Inserts a word into the trie. */
    void insert(string word) {
        TriedTreeNode* p = root;
        for (auto & c : word){
            int i = c - 'a';
            if (!p->childrens[i]){
                p->childrens[i] = new TriedTreeNode();
            }
            p = p->childrens[i];
        }
        p->flag = true;
    }
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TriedTreeNode* p = root;
        for(auto& c : word){
            int i = c - 'a';
            if(!p->childrens[i]){
                return false;
            }
            p = p->childrens[i];
        }
        return p->flag;
    }
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TriedTreeNode* p = root;
        for (auto & c : prefix){
            int i = c - 'a';
            if (!p->childrens[i]){
                p->childrens[i] = new TriedTreeNode();
            }
            p = p->childrens[i];
        }
        return true;
    }
};

//Accepted
/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */