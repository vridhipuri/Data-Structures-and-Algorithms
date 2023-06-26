//Count set bits in an integer
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int setBits(int N) {
        // Write Your Code here
        int count=0;
        if(N & 1==1)
        {
            count=1;
        }
        int temp=N;
        while(temp!=0)
        {
            temp=temp>>1;
            if(temp & 1==1)
            {
                count++;
            }
        }
        return count;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;

        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}

// } Driver Code Ends