//3Sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;
        set<vector<int>>s;
        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++)
        {
            m[nums[i]]=i;
        }

        for(int i=0;i<nums.size()-2;i++)
        {
            for(int j=i+1;j<nums.size()-1;j++)
            {
                if((m.find(-(nums[i]+nums[j]))!=m.end()) && i!=j &&
                i!=m[nums[i]] && j!=m[nums[i]])
                {
                    //ans.push_back({nums[i],nums[j],-(nums[i]+nums[j])});
                    s.insert({nums[i],nums[j],-(nums[i]+nums[j])});
                }
            }
        }
        int i=0;
        for(auto it:s)
        {
            ans.push_back(it);
            i++;
        }
        return ans;
    }
};