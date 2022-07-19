class Node{
    public:
    Node* link[26];
    
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
};
class Trie {
public:
    Node * root;
    
    Trie() {
        root = new Node();
    }
    
    int insert(string word) {
        Node* node = root;
        int count = 0;
        for(int i=0;i<word.size();i++)
        {
            if(!node->containsKey(word[i]))
            {
                node->put(word[i],new Node());
                count++;
            }
            node = node->get(word[i]);
        }
    return count;
    }
};
int countDistinctSubstrings(string &s)
{    
    Trie T;
    int ans=0;
    
    for(int i=0;i<s.size();i++)
    {
        ans += T.insert(s.substr(i,s.size()-i));
    }
    
    return ans+1;
}