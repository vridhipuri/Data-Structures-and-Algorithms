//Frog Jump (see copy)
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    //space optimization
    
    int prev=0;
    int prev1=0;
    int curr;
    for(int i=1;i<n;i++)
    {
        int left=prev+abs(heights[i]-heights[i-1]);
        int right=INT_MAX;
        if(i>1)
            right=prev1+abs(heights[i]-heights[i-2]);
        curr=min(left,right);
        prev1=prev;
        prev=curr;
    }
    return prev;
}