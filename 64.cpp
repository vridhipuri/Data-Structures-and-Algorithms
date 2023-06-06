//Print all Subsequences of a string. (see vid https://www.youtube.com/watch?v=OZiTiLDZJ60)

#include<iostream>
using namespace std;


int subsequences(string output[],string s)
{
    //base case
    if(s.length()==0)
    {
        output[0]="";
        return 1; //only 1 subsequence for empty string
    }
    int smallerOutputSize=subsequences(output,s.substr(1));
    for(int i=0;i<smallerOutputSize;i++)
    {
        output[smallerOutputSize+i]=s[0]+output[i]; //concatenated subsequence of string will be placed at (smallerOutputSize+i)th index
    }
    return 2*smallerOutputSize;
}
int main()
{
    string s="abcd";
    string output[1000];
    int outputSize=subsequences(output,s);

    //print subsequences
    for(int i=0;i<outputSize;i++)
    {
        cout<<output[i]<<" ";
    }
    return 0;

}