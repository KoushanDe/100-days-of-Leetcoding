class Node{
    public:
    Node* link[26];
    bool isEnd=false;
    
    bool containsKey(char ch){
        return link[ch-'a']!=NULL;
    }
    void put(char ch, Node* node)
    {
        link[ch-'a'] = node;
    }
    
    Node* get(char ch)
    {
        return link[ch-'a'];
    }
    
    void setEnd()
    {
        isEnd=true;
    }
    
    bool getEnd()
    {
        return isEnd;
    }
};
class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node();
    }
    
    void insert(string word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }
    
    bool search(string word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
                node = node->get(word[i]);
            else
                return false;
        }
        
        return node->getEnd();
    }
    
    bool startsWith(string prefix) {
        Node* node = root;
        
        for(int i=0;i<prefix.size();i++)
        {
            if(node->containsKey(prefix[i]))
                node = node->get(prefix[i]);
            else
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