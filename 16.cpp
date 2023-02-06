//find duplicate in an array of N+1 Integers (see copy)
class Solution {
public:
    int findDuplicate(vector<int>& nums) 
    {
        //approach 3
       /* int i,x;
        unordered_set<int>s;
        for(i=0;i<nums.size();i++)
        {
            if(s.find(nums[i])!=s.end())
            {
                x=nums[i];
                break;
            }
            s.insert(nums[i]);
        }
        return x;*/

        //approach 4 - efficient

        int slow=0;
        int fast=0;
        //find intersction of loop
        do{
            slow=nums[slow]; //slow=head->next
            fast=nums[nums[fast]]; //fast=head->next->next
            if(fast==slow) //loop found
            {
                break;
            }
        }while(fast!=slow);
        
        //find repeating element/starting point of loop 
        //slow=head; fast=same pos
        slow=0;
        while(slow!=fast)
        {
            slow=nums[slow];  //slow=slow->next
            fast=nums[fast];  //fast=fast->next
        }
        return slow;
    }
};