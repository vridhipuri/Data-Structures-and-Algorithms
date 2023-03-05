//kth largest element in an array
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<queue>
using namespace std;

int solve(int arr[], int n,int k){
    priority_queue<int>pq;
    for(int i=0;i<k;i++)
    {
        pq.push((-1)*arr[i]);
    }
    for(int i=k;i<n;i++){
        if(arr[i]>(-1)*pq.top()){
            pq.pop();
            pq.push((-1)*arr[i]);
        }
    }
    return (-1)*pq.top();
}
int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int k;
    cin>>k;
    cout<<solve(arr,n,k);
    return 0;
}
