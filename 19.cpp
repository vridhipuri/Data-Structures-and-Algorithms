//Next Permutation (see copy)
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int index=-1;
        for(int i=nums.size()-1;i>0;i--)
        {
            if(nums[i]>nums[i-1])
            {
                index=i;
                break;
            }
        }
        if(index==-1) //array present in descending order
        {
            reverse(nums.begin(),nums.end()); //next permutation will be array in ascending order
        }
        
        else //index found
        {
            int prev=index;
            for(int i=index+1;i<nums.size();i++)
            {
                if(nums[i]>nums[index-1] && nums[i]<=nums[prev])
                {
                    prev=i;
                }
            }
            swap(nums[index-1],nums[prev]);
            reverse(nums.begin()+index,nums.end());
        }
    }
};