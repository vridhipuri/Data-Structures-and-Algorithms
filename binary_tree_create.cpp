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
node* create(node* root)
{
    int val;
    cout<<"Enter data "<<endl;
    cin>>val;
    root=new node(val);
    if(val==-1)
        return NULL;
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
    return 0;
}