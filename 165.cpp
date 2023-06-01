//Flatten a Linked List

//{ Driver Code Starts
#include <bits/stdc++.h>

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
Node* merge(Node* one, Node* two)
{
    if(one->bottom==NULL)
    {
        one->bottom=two;
        return one;
    }
    Node* curr1=one;
    Node* curr2=two;
    Node* next1=one->bottom;
    while(next1!=NULL and curr2!=NULL)
    {
        if(curr2->data>=curr1->data and curr2->data<=next1->data)
        {
            curr1->bottom=curr2;
            Node* next2=curr2->bottom;
            curr2->bottom=next1;
            //update pointers
            curr1=curr2;
            curr2=next2;
        }
        else
        {
            curr1=next1;
            next1=next1->bottom;
            if(next1==NULL)
            {
                curr1->bottom=curr2;
                return one;
            }
        }
    }
    return one;
}
Node *flatten(Node *root)
{
   //base cases
   if(root==NULL) //no node
   {
       return NULL;
   }
   if(root->next==NULL) //one node
   {
       return root;
   }
   //check to merge
   if(root->data<root->next->data)
   
        return merge(root,flatten(root->next));
   
  else
       return merge(flatten(root->next),root);
}

