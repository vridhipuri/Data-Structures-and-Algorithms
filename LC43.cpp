//43. Multiply Strings

class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")
        {
            return "0";
        }
        vector<int>ans(num1.size()+num2.size(),0);
        for(int i=num1.size()-1;i>=0;i--)
        {
            for(int j=num2.size()-1;j>=0;j--)
            {
                ans[i+j+1]=ans[i+j+1]+(num1[i]-'0')*(num2[j]-'0');
                ans[i+j]=ans[i+j]+ans[i+j+1]/10;
                ans[i+j+1]=ans[i+j+1]%10;
            }
        }
        //remove preceeding zeroes
        int i=0;
        while(i<ans.size() && ans[i]==0)
        {
            i++;
        }
        string res="";
        for(int j=i;j<ans.size();j++)
        {
            res.push_back(ans[j]+'0');
        }
        return res;
    }
};