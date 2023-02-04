//Count and Say problem (see copy and do dry run)

class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";   
        string str=countAndSay(n-1);
        int count=1;
        int i=1;
        int num=str[0]-'0';
        string t="";
        while(i<str.length())
        {
            if(num==str[i]-'0')
            {
                count++;
            }
            else{
                t=t+to_string(count);
                t=t+to_string(num);
                num=str[i]-'0';
                count=1;
            }
            i++;
        } 
        t=t+to_string(count);
        t=t+to_string(num);
        return t;
    }
};