//post order traversal
#include<iostream>
using namespace std;
class node{
    public:
    int data;
    node* left;
    node* right;

    node(int d)
    {
        this->data=d;
        this->left=NULL;
        this->right=NULL;
    }
};
void postorder(node* root)
{
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
node* create(node* root)
{
    int val;
    cout<<"Enter data "<<endl;
    cin>>val;
    if(val==-1)
        return NULL;
    root=new node(val);
    cout<<"Enter data to insert in left of "<<val<<endl;
    root->left=create(root->left);
    cout<<"Enter data to insert in right of "<<val<<endl;
    root->right=create(root->right);
    return root;
}
int main()
{
    node* root=NULL;
    root=create(root);
    postorder(root);
    return 0;
}