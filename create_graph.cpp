//graph using adjacency list
#include<iostream>
#include<unordered_map>
#include<list>

using namespace std;

class Graph{
    public:
    unordered_map<int,list<int>> adj;
    
    void addEdge(int u,int v,bool direction)
    {
        //direction=0 - undirected
        //direction=1 - directed
        
        adj[u].push_back(v);   //add edge from u to v

        if(direction==0){
            adj[v].push_back(u);
        } //if undirected add edge from v to u
    }
    void print(){
        for(auto i: adj)
        {
            cout<<i.first<<"->" ; //print node
            for(auto j:i.second) //print list of nodes jinse i.first connected hai
            {
                cout<<j<<" ";
            }
            cout<<endl;
        }
    }

};

int main()
{
    Graph g;
    int u,v,m,n;
    
    cout<<"Enter number of nodes"<<endl;
    cin>>n;
    cout<<"Enter number of edges"<<endl;
    cin>>m;
    for(int i=0;i<m;i++)
    {
        cin>>u>>v;
        g.addEdge(u,v,0); //undirected
    }
    g.print();
    return 0;
}