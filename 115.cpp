//Sort by Set Bit Count
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution{
    public:
    
    static bool compare(int a,int b)
        {
            //this function for counting set bits and we are comparing jiski
            //set bits zyada hai vo return ho
            return __builtin_popcount(a)>__builtin_popcount(b);
        }
    void sortBySetBitCount(int arr[], int n)
    {
        //agar 2 nos have same value toh this func arranges them acc to their
        //order in the input array
        stable_sort(arr,arr+n,compare);
        
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int arr[n];
        for(int i=0;i<n;i++){
            cin>>arr[i];
        }
        Solution ob;
        ob.sortBySetBitCount(arr, n);
        for (int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends