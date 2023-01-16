#include<iostream>
#include<queue>
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
void levelOrderTraversal(node* root)
{
    queue<node*>q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* temp=q.front();
        q.pop();
        if(temp==NULL) //next line mein print krne ke liye
        {
            cout<<endl;
            if(!q.empty())
            {
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left!=NULL)
                q.push(temp->left);
            if(temp->right!=NULL)
                q.push(temp->right);
        }
    }
}
int main()
{
    node* root=NULL;
    root=create(root);
    levelOrderTraversal(root);
    return 0;
}