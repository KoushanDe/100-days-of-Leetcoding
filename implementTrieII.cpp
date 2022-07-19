class Node{
    public:
    Node* link[26];
    int cntPrefix=0;
    int cntWord=0;
    
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
    
    void addPrefixCnt()
    {
        cntPrefix++;
    }
    void addWordCnt()
    {
        cntWord++;
    }
    void deletePrefix()
    {
        cntPrefix--;
    }
    void deleteWord()
    {
        cntWord--;
    }
    
    int getPrefixCnt()
    {
        return cntPrefix;
    }
    int getWordCnt()
    {
        return cntWord;
    }
};
class Trie{

    public:
    Node* root;
    Trie(){
        // Write your code here.
        root = new Node();
    }

    void insert(string &word){
        // Write your code here.
       Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
            }
            node= node->get(word[i]);
            node->addPrefixCnt();
        }
        node->addWordCnt();
    }

    int countWordsEqualTo(string &word){
        // Write your code here.
         Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getWordCnt();
    }

    int countWordsStartingWith(string &word){
        // Write your code here.
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(node->containsKey(word[i]))
            {
                node = node->get(word[i]);
            }
            else
                return 0;
        }
        return node->getPrefixCnt();
    }

    void erase(string &word){
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            node = node->get(word[i]);
            node->deletePrefix();
        }
        node->deleteWord();
    }
};
