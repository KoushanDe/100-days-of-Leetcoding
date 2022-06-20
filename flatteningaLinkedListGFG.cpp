
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};

using namespace std;

void printList(Node *Node)
{
    while (Node != NULL)
    {
        printf("%d ", Node->data);
        Node = Node->bottom;
    }
}

Node* flatten (Node* root);

int main(void) {

	int t;
	cin>>t;
	while(t--){
    int n,m,flag=1,flag1=1;
    struct Node * temp=NULL;
	struct Node * head=NULL;
	struct Node * pre=NULL;
	struct Node * tempB=NULL;
	struct Node * preB=NULL;
		cin>>n;
        int work[n];
		for(int i=0;i<n;i++)
            cin>>work[i];
		for(int i=0;i<n;i++){
			m=work[i];
			--m;
			int data;
			scanf("%d",&data);
			temp = new Node(data);
			temp->next = NULL;
			temp->bottom = NULL;
			
			if(flag){
				head = temp;
				pre = temp;
				flag = 0;
				flag1 = 1;
			}
			else{
				pre->next = temp;
				pre = temp;
				flag1 = 1;
			}
			for(int j=0;j<m;j++){
				
				int temp_data;
				scanf("%d",&temp_data);
				tempB = new Node(temp_data);

				if(flag1){
					temp->bottom=tempB;
					preB=tempB;
					flag1=0;
				}
				else{
					preB->bottom=tempB;
					preB=tempB;
				}
			}
		}
		   Node *fun = head;
		   Node *fun2=head;

            Node* root = flatten(head);
            printList(root);
            cout<<endl;

	}
	return 0;
}
// } Driver Code Ends


/* Node structure  used in the program

struct Node{
	int data;
	struct Node * next;
	struct Node * bottom;
	
	Node(int x){
	    data = x;
	    next = NULL;
	    bottom = NULL;
	}
	
};
*/

/*  Function which returns the  root of 
    the flattened linked list. */
    Node* mergeTwoLists(Node* list1, Node* list2) {
        if(list1==NULL)return list2;
        if(list2==NULL)return list1;
        
        Node* list3;
        Node* curr=new Node(0);
        
        list3=curr;
        
        while(list1!=NULL&&list2!=NULL)
        {
            if(list1->data<list2->data)
            {   
                curr->bottom=list1;
                //cout<<curr->val<<"first";
                list1 = list1->bottom;
            }
            else
            {
                curr->bottom=list2;
                //cout<<curr->val<<"second";
                list2 = list2->bottom;
            }
            
                curr=curr->bottom;
        }
        
        while(list1!=NULL)
        {
            curr->bottom=list1;
            curr=curr->bottom;
            //cout<<curr->val<<"third";
            list1=list1->bottom;
        }
        while(list2!=NULL)
        {
            curr->bottom=list2;
            curr=curr->bottom;
            //cout<<curr->val<<"last";
            list2=list2->bottom;
        }
        
        return list3->bottom;
    }
Node *flatten(Node *root)
{
   if(root==NULL||root->next==NULL) return root;
   
   Node* ans = root;
   Node* temp = root;
   root = root->next;
   
   while(root!=NULL)
   {
       Node* l1 = temp;
       Node* l2 = root;
       root=root->next;
       
       temp = mergeTwoLists(l1,l2);
   }
   
   ans->next = NULL;
   return ans;
   
}

