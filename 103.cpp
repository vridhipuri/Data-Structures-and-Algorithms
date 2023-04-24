//square root of an integer (count squares)

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int countSquares(int N) {
        /* n=9 and sqrt(9)=3
        so 3 se pehle 2 hi nos honge which give perfect squares ie 1 and 4.
        now let n=25 and sqrt(25)=5
        so 25 se pehle perfect squares are 1,4,9,16 ie 5-1=4 nos.*/
        
        int a=sqrt(N);
        if(a*a==N)
        {
            return a-1;
        }
        else
        return a;
       
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}
// } Driver Code Ends