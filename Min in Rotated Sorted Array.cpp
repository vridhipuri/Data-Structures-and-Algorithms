//Find Minimum in Rotated Sorted Array (see copy)
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int solve(int arr[],int n){
    int low=0;
    int high=n-1;
    int mid;
    if(n==1){
        return arr[0];
    }
    if(arr[0]<arr[high]) //if array is sorted and not rotated
    {
        return arr[0];
    }
    while(low<=high){
        mid=(low+high)/2;
        if(low<mid && arr[mid]<arr[mid-1]){
            return arr[mid];
        }
        else if(high>mid && arr[mid+1]<arr[mid]){
            return arr[mid+1];        
        }
        else if(arr[high]>arr[mid]){
            high=mid-1;
        }
        else{
            low=mid+1;
        }
    }
    return -1;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */   
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    cout<<solve(arr,n);
    return 0;
}
