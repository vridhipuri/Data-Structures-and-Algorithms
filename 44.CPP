//Search an element in a matriix
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
       int row=matrix.size(); //row size
       int col=matrix[0].size(); //col size
       //we are treating it like 1d array as all elements are sorted 
       int start=0;
       int end=(row*col)-1;
       int mid;
       while(start<=end)
       {
           mid=(start+end)/2; //mid in 1d array
           int mid_in_matrix=matrix[mid/col][mid%col]; //1d array ka mid in 2d array
           if(mid_in_matrix==target)
           {
               return true;
           }
           else if(mid_in_matrix<target)
           {
               start=mid+1;
           }
           else{
               end=mid-1;
           }
       }
       return false;
    }
};