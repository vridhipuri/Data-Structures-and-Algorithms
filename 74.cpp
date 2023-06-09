//Convert a Sentence into its equivalent mobile numeric keypad sequence.

#include<iostream>
using namespace std;

int main()
{
    string s="GEEKSFORGEEKS";

    //this is according phone keypad
                              //A  //B  //C   //D  //E  //F  //G  //H  //I  //J //K  //L   //M  //N  //O
    string noOfTimesPressed[]={"2","22","222","3","33","333","4","44","444","5","55","555","6","66","666"
    "7","77","777","7777","8","88","888","9","99","999","9999"};
    //P  //Q  //R  //S    //T //U //V    //W  X   Y        Z


    string ans="";

    for(int i=0;i<s.length();i++)
    {
        if(s[i]==' ') //if space there (space is a char in s so single quotes)
        {
            ans=ans+'0'; //space means 0 in keypad
        }
        else{
            int j=s[i]-'A';  // calculating the difference between the ASCII values of s[i] and 'A'
            ans=ans+noOfTimesPressed[j];
        }
    }
    cout<<ans;
    return 0;
}