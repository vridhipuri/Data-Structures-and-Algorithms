//Print all the permutations of the given string (see lpve babbar vid)
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
	public:
	
	    void recursion(string S,vector<string> &temp, int index)
	    {
	        if(index>=S.length())
	        {
	           temp.push_back(S);
	           return;
	        }
	        for(int i=index;i<S.length();i++)
	        {
	            swap(S[i],S[index]);
	            recursion(S,temp,index+1);
	            //backtrack
	            swap(S[i],S[index]);
	        }
	    }
		vector<string>find_permutation(string S)
		{
		    // Code here there
		    vector<string>temp;
		    int index=0;
		    recursion(S,temp,index);
		    sort(temp.begin(),temp.end());
		    //to get unique array of permutations
		    vector<string>ans;
		    ans.push_back(temp[0]);
		    for(int i=1;i<temp.size();i++)
		    {
		        if(temp[i]!=temp[i-1])
		        {
		            ans.push_back(temp[i]);
		        }
		    }
		    return ans;
		}
};



//{ Driver Code Starts.
int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}

// } Driver Code Ends