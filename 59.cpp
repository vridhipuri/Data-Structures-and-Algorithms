//Write a Code to check whether one string is a rotation of another
class Solution {
public:
    bool rotateString(string s, string goal) {
        string s1=s+s; //concatenated so s1 will include all rotations of s
        if(s.length()==goal.length())
        {
            if(s1.find(goal)!=-1) //finds 1st occurance of a substring goal in s1
            {
                return true;
            }
            
        }
        return false;
     }
};