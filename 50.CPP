//Rotate matrix by 90 degrees
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                //do transpose first
                int temp= matrix[i][j];
                matrix[i][j]=matrix[j][i];
                matrix[j][i]=temp;
            }
        }
        //reverse/swap columns
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n/2;j++) //n/2 as all columns will be swapped aadhe mein
            {
                int temp= matrix[i][j];
                matrix[i][j]=matrix[i][n-1-j];
                matrix[i][n-1-j]=temp;
            }
        }
       
    }
};