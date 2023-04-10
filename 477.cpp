//House Robber II (see copy)
#include <bits/stdc++.h> 

long long int prevQues(vector<int> &arr)
{
    long long int n=arr.size();
    long long int prev=arr[0];
    long long int prev2=0;
    long long int curr;
    long long int pick,nonpick;
    for(int i=1;i<n;i++)
    {
        pick=arr[i];
        if(i>1)
        {
            pick=pick+prev2;
        }
        nonpick=0+prev;
        curr=max(pick,nonpick);
        prev2=prev;
        prev=curr;
    }
    return prev;
}
long long int houseRobber(vector<int>& valueInHouse)
{
    // Write your code here.
    int n=valueInHouse.size();
    vector<int>temp1,temp2;
    //if array has single element
    if(n==1)
        return valueInHouse[0];
    for(int i=0;i<n;i++)
    {
        //ignore 1st element
        if(i!=0)
        {
            //make a temp array 
            temp1.push_back(valueInHouse[i]); //includes last
        }
        //ignore last element
        if(i!=n-1)
        {
            temp2.push_back(valueInHouse[i]); //includes 1st
        }
    }
    return max(prevQues(temp1),prevQues(temp2));
}