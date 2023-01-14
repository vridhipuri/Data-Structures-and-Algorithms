//Sort an array of 0s, 1s and 2s
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



// } Driver Code Ends
class Solution
{
    public:
    
    void swap(int *a, int *b)
    {
        int temp=*a;
        *a=*b;
        *b=temp;
    }
    void sort012(int a[], int n)
    
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]==0){
                swap(& a[count],& a[i]);
                count++;
            }
            
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]==1){
                swap(& a[count],& a[i]);
                count++;
            }
        }  //2 automatically end mein aajayega
        
    }
    
};

//{ Driver Code Starts.
int main() {

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >>n;
        int a[n];
        for(int i=0;i<n;i++){
            cin >> a[i];
        }

        Solution ob;
        ob.sort012(a, n);

        for(int i=0;i<n;i++){
            cout << a[i]  << " ";
        }

        cout << endl;
        
        
    }
    return 0;
}


// } Driver Code Ends