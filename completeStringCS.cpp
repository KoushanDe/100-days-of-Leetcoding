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
    
    void insert(string& word) {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
                node->put(word[i],new Node());
            
            node = node->get(word[i]);
        }
        
        node->setEnd();
    }
    
    bool isComplete(string& word)
    {
        Node* node = root;
        
        for(int i=0;i<word.size();i++)
        {
             node = node->get(word[i]);
            if(!node->getEnd())
                return false;
        }
        return true;
    }
};
string completeString(int n, vector<string> &a){
    Trie T;
    
    for(int i=0;i<a.size();i++)
    {
        T.insert(a[i]);
    }
    string ans = "";
    for(int i=0;i<a.size();i++)
    {
        if(T.isComplete(a[i]))
        {
            if(a[i].size()>ans.size())
                ans=a[i];
            else if(a[i].size()==ans.size())
                ans = min(a[i],ans);
        }
    }
    
    return ans==""?"None":ans;
}