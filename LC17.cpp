//17. Letter Combinations of a Phone Number

class Solution {

    public:

    void recursion(vector<string> v, vector<string> &output,int num, string ans)
    {
        if(num==0)
        {
            output.push_back(ans);
            return;
        }
        int i=num%10;
        string s=v[i];
        for(int j=0;j<s.length();j++)
        {

            recursion(v,output,num/10,s[j]+ans);
        }
    }
    vector<string> letterCombinations(string digits) {

        if(digits.length()==0)
        {
            return {};
        }
        vector<string> v= {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};

        vector<string>output;
        string ans="";
        int num=stoi(digits);
        recursion(v,output,num,ans);
        return output;
        
    }
};