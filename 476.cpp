//Maximum sum of non-adjacent elements (see copy)
#include <bits/stdc++.h>
int maximumNonAdjacentSum(vector<int> &nums) {
  // Write your code here.
  int prev = nums[0];
  int prev2 = 0;
  for (int i = 0; i < nums.size(); i++)
  {
      int pick=nums[i];
      if(i>1)
      {
          pick=pick+prev2;
      }
      int nonpick=0+prev;
      int curr=max(pick,nonpick);
      prev2=prev;
      prev=curr;

  }
  return prev;
}