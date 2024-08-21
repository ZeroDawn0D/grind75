// memory efficient, but runtime can be made better ig
class Node{
public:
    vector<Node*> children;
    char c;
    bool is_end;
    Node(char ch){
        children = {};
        c = ch;
        is_end = false;
    }
};

class Trie {
public:
    Node* root;
    Trie() {
        root = new Node('\0');

    }
    
    void insert(string word) {
        Node* cur_node = root;
        char cur_ch;
        for(int i = 0; i < word.size(); i++){
            cur_ch = word[i];
            vector<Node*> &cur_children = cur_node->children;
            int j;
            bool found_node = false;
            for(j = 0;j<cur_children.size();j++){
                if(cur_children[j]->c == cur_ch){
                    cur_node = cur_children[j];
                    found_node = true;
                    break;
                }
            }
            if(found_node){
                continue;
            }
            cur_children.push_back(new Node(cur_ch));
            cur_node = cur_children[j];
        }
        cur_node->is_end = true;
    }
    
    bool search(string word) {
        Node* cur_node = root;
        char cur_ch;
        for(int i = 0; i < word.size();i++){
            cur_ch = word[i];
            vector<Node*> &cur_children = cur_node->children;
            int j;
            bool found_node = false;
            for(j = 0;j<cur_children.size();j++){
                if(cur_children[j]->c == cur_ch){
                    cur_node = cur_children[j];
                    found_node = true;
                    break;
                }
            }
            if(found_node){
                continue;
            }
            return false;
        }
        return cur_node->is_end;
    }
    
    bool startsWith(string prefix) {
        Node* cur_node = root;
        char cur_ch;
        for(int i = 0; i < prefix.size();i++){
            cur_ch = prefix[i];
            vector<Node*> &cur_children = cur_node->children;
            int j;
            bool found_node = false;
            for(j = 0;j<cur_children.size();j++){
                if(cur_children[j]->c == cur_ch){
                    cur_node = cur_children[j];
                    found_node = true;
                    break;
                }
            }
            if(found_node){
                continue;
            }
            return false;
        }
        return true;
    }
};


/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
