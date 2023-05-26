//Merge Sort for Linked List
//{ Driver Code Starts
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


// } Driver Code Ends
/* Structure of the linked list node is as
struct Node 
{
    int data;
    struct Node* next;
    Node(int x) { data = x;  next = NULL; }
};
*/
class Solution{
  public:
    Node* merge(Node* one, Node* two)
    {
        if(one==NULL)
        {
            return two;
        }
        if(two==NULL)
        {
            return one;
        }
        if(one->next==NULL)
        {
            one->next=two;
            return one;
        }
        Node* curr1=one;
        Node* next1=curr1->next;
        Node* curr2=two;
    while(next1!=NULL && curr2!=NULL){
        if(curr2->data>=curr1->data && curr2->data<=next1->data)
        {
            curr1->next=curr2;
            Node *next2=curr2->next;
            curr2->next=next1;
            //update pointers
            curr1=curr2;
            curr2=next2;
            
        }
        else{
            curr1=next1;
            next1=next1->next;
            if(next1==NULL)
            {
                curr1->next=curr2;
                return one;
            }
        }

     }
     return one;
    }
    //Function to sort the given linked list using Merge Sort.
    Node* mergeSort(Node* head) {
        
        //base case
        if(head==NULL || head->next==NULL)
        {
            return head;
        }
        //divide list into 2 parts by finding mid
        Node* slow=head;
        Node* fast=head->next;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* mid=slow;
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;
        left=mergeSort(left);
        right=mergeSort(right);
        if(left->data<right->data)
        {
            return merge(left,right);
        }
        else{
            return merge(right,left);
        }
        
    }
};


//{ Driver Code Starts.

void printList(Node* node) {
    while (node != NULL) {
        printf("%d ", node->data);
        node = node->next;
    }
    printf("\n");
}

void push(struct Node** head_ref, int new_data) {
    Node* new_node = new Node(new_data);

    new_node->next = (*head_ref);
    (*head_ref) = new_node;
}

int main() {
    long test;
    cin >> test;
    while (test--) {
        struct Node* a = NULL;
        long n, tmp;
        cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> tmp;
            push(&a, tmp);
        }
        Solution obj;
        a = obj.mergeSort(a);
        printList(a);
    }
    return 0;
}
// } Driver Code Ends