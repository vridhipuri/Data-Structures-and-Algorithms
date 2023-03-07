//Minimum Moves to Equal Array Elements (see copy)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    vector<int>v;
    int x;
    for(int i=0;i<n;i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    int median;
    if(n%2!=0)
    {
        median=v[n/2];
    }
    else{
        median=(v[(n/2)]+v[(n/2)-1])/2;
    }
    int moves=0;
    
    for(int i=0;i<n;i++)
    {
        moves=moves+abs(v[i]-median);
    }
    cout<<moves;
    return 0;
}