//Find the first circular tour that visits all Petrol Pumps (see copy)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


// } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
       int i=0;
       int start=0;
       int balance=0;
       int deficit=0;
       while(i<n)
       {
           balance=balance+p[i].petrol-p[i].distance; // to access structure variables
           if(balance<0)
           {
               deficit=deficit+balance;
               i=i+1;
               start=i;
               balance=0;
           }
           else
            i++;
       } //circle mein nhi chale to not traverse prev nodes again instead check krliya agar balance+defict +vee hai toh start mil chuka hai
       if(balance+deficit>=0) 
        return start;
       return -1;
    }
};



//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}

// } Driver Code Ends