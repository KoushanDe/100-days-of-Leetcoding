//ALL TEST CASE PASSED, BUT MEMORY LIMIT EXCEEDED
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        //cout<<"serialise"<<endl;
        if(root==NULL) return "";
        queue<TreeNode*> q;
        string s = "";
        q.push(root);
        //TreeNode* dummy = new TreeNode(0);
        
        while(!q.empty())
        {
            TreeNode* temp = q.front();
            q.pop();
            if(temp!=NULL)
                s = s + to_string(temp->val)+" ";
            else
            {
                s = s + "# ";
                continue;
            }
            
            
            

            q.push(temp->left);
            q.push(temp->right);   
        }
        //cout<<s;
        //cout<<"serialise"<<endl;
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        //cout<<"deserialise"<<endl;
        if(data=="")return NULL;
        
        int i=0;
        queue<TreeNode*> q;
        int space = data.find(" ",i);
        //cout<<space<<endl;
        string temp = data.substr(i,space-i);
        //cout<<temp<<endl;
        i=space+1;
        TreeNode* root = new TreeNode(stoi(temp));
        TreeNode* ans = root;
        q.push(root);
        while(i<data.size())
        {   
            root = q.front();
            q.pop();
            space = data.find(" ",i);
            //cout<<space<<endl;
            temp = data.substr(i,space-i);
            //cout<<temp<<endl;
            i=space+1;
            
            if(temp!="#")
            {
                TreeNode* node = new TreeNode(stoi(temp));
                root->left = node;
            }
            else
            {
                root->left=NULL;
            }
            //if(i>data.size()) break;
            space = data.find(" ",i);
            //cout<<space<<endl;
            temp = data.substr(i,space-i);
            //cout<<temp<<endl;
            i=space+1;
            
            if(temp!="#")
            {
                TreeNode* node = new TreeNode(stoi(temp));
                root->right = node;
            }
            else
            {
                root->right=NULL;
            }
            
            if(root->left)q.push(root->left);
            if(root->right)q.push(root->right);
        }
        //cout<<"deserialise"<<endl;
        return ans;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));