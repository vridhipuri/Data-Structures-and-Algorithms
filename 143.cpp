//Remove Duplicates in a sorted Linked List.
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
    cout<<temp->data<<" ";
    temp=temp->next;
    }
}
Node* removeDuplicates(Node *root);
int main() {
	// your code goes here
	int T;
	cin>>T;

	while(T--)
	{
		int K;
		cin>>K;
		Node *head = NULL;
        Node *temp = head;

		for(int i=0;i<K;i++){
		int data;
		cin>>data;
			if(head==NULL)
			head=temp=new Node(data);
			else
			{
				temp->next = new Node(data);
				temp=temp->next;
			}
		}
		
		Node *result  = removeDuplicates(head);
		print(result);
		cout<<endl;
	}
	return 0;
}
// } Driver Code Ends


/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};*/

//Function to remove duplicates from sorted linked list.
Node *removeDuplicates(Node *head)
{
    
    Node* temp=head;
    //Node* temp1=head->next;
    while(temp!=NULL)
    {
        if((temp->next!=NULL) && temp->data==temp->next->data)
        {
           Node *t=temp->next; 
           temp->next=t->next;
           delete t;
           //temp ko aage nhi badha rhe coz agar maanlo 3 elements same hote like 1 2 3 3 3 5
           //toh mid wala 3 jab del krke temp aage badhate toh next iteration mein
           //3 or 5 compare hota and bas ek 3 remove hota
        }
        else{
            temp=temp->next;
        }
    }
    return head;
}