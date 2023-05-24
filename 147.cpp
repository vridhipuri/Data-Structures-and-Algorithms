//Add two numbers represented by linked lists.
//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
/* node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

*/

class Solution
{
    public:
    Node* reverse(Node* head)
        {
            Node *curr=head;
            Node* temp=curr;
            Node *prev=NULL;
            while(curr!=NULL)
            {
                temp=curr->next;
                curr->next=prev;
                prev=curr;
                curr=temp;
            }
            return prev;
        }
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
      Node* curr=new Node(0);   //dummy node 
      Node* head=curr;
      Node* head1=reverse(first);
      Node* head2=reverse(second);
      Node* curr1=head1;
      Node* curr2=head2;
      int sum,carry;
      sum=carry=0;
      while(curr1!=NULL and curr2!=NULL)
      {
          sum=(curr1->data)+(curr2->data)+carry;
          carry=sum/10;
          Node* n=new Node(sum%10);
          if(curr==NULL)
          {
              curr=n;
              curr->next=NULL;
              head=n;
          }
          else{
                curr->next=n;
                curr=n;
                curr->next=NULL;
            }
          carry=sum/10;
          curr1=curr1->next;
          curr2=curr2->next;
      }
      while(curr1!=NULL)
      {
          sum=(curr1->data)+carry;
          Node* n=new Node(sum%10);
          if(curr==NULL)
          {
              curr=n;
              curr->next=NULL;
              head=n;
          }
          else{
                curr->next=n;
                curr=n;
                curr->next=NULL;
            }
          carry=sum/10;
          curr1=curr1->next;
          
      }
      while(curr2!=NULL)
      {
          sum=(curr2->data)+carry;
          Node* n=new Node(sum%10);
          if(curr==NULL)
          {
              curr=n;
              curr->next=NULL;
              head=n;
          }
          else{
                curr->next=n;
                curr=n;
                curr->next=NULL;
            }
          carry=sum/10;
          curr2=curr2->next;
      }
      while(carry!=0)
      {
          sum=carry;
          Node* n=new Node(sum%10);
          if(curr==NULL)
          {
              curr=n;
              curr->next=NULL;
              head=n;
          }
          else{
                curr->next=n;
                curr=n;
                curr->next=NULL;
            }
          carry=sum/10;
      }
     return reverse(head->next);
     
      
      
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends