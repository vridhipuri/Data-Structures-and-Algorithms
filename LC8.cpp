//String to Integer (atoi)

class Solution {
public:
    int myAtoi(string s) {
        //   0 1 2 3 4 5 6 7 8 9 10 11
        //eg _ _ _ - 4 1 2 6 a b c d

        long ans=0;
        int i=0;
        int sign=+1;
        int n=s.length();
        if(n==0)
        {
            return 0;
        }
        while(i<n && s[i]==' ')
        {
            i++; //i becomes 3
        }
        s=s.substr(i); //ignore the leading white spaces and we get string from i=3 to end

        //string becomes
        //0 1 2 3 4 5 6 7 8
        //- 4 1 2 6 a b c d
        //i

        //if no.is negative toh starting mein sign hoga eg -214 (agar white space na hoti toh)
        if(s[0]=='-')
        {
            sign=-1;
        }

        //now if string has white space then 2 cases
        //1. white space ke baad there is a sign so we start i from 1 as sign is at 0th index
        //2. no sign after white space so indexing starts from 1

        if(s[0]=='-' || s[0]=='+')
        {
            i=1;
        }
        else {
            i=0;
        }
        int maxi=INT_MAX;
        int mini=INT_MIN;
        while(i<n)
        {
            if(!isdigit(s[i]))
            {
                break;
            }
            ans=ans*10+(s[i]-'0');
            if(sign==1 && ans>maxi)
            {
                return maxi;
            }
            if(sign==-1 && -1*ans<mini)
            {
                return mini;
            }
            i++;

        }
        return (int)(ans*sign);

    }
};