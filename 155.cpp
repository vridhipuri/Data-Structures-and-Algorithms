//Write a Program to check whether the Singly Linked list is a palindrome or not.

//{ Driver Code Starts
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;
/* Link list Node */
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};




// } Driver Code Ends
/*
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

class Solution{
  public:
    Node* reverse(Node* head)
    {
        Node* curr=head;
        Node* prev=NULL;
        Node* n=NULL;
        while(curr!=NULL)
        {
            n=curr->next;
            curr->next=prev;
            prev=curr;
            curr=n;
        }
        return prev;
    }
    //using fast and slow pointer technique
    bool isPalindrome(Node *head)
    {
        if(head==NULL || head->next==NULL)
            return true;
        Node* slow=head;
        Node* fast=head;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* mid=slow; //find mid using fast and slow pointer
        Node* temp=reverse(mid); //reverse the LL starting from mid
        //check for palindrome
        Node* curr=head;
        while(temp!=NULL && curr!=temp)
        {
            if(curr->data!=temp->data)
            {
                return false;
            }
            else{
                curr=curr->next;
                temp=temp->next;
            }
        }
        return true;
    }
};



//{ Driver Code Starts.
/* Driver program to test above function*/
int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        // taking first data of LL
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        // taking remaining data of LL
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
    Solution obj;
   	cout<<obj.isPalindrome(head)<<endl;
    }
    return 0;
}


// } Driver Code Ends