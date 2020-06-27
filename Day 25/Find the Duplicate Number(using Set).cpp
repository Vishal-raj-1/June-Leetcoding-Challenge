class Solution {
public:
    int findDuplicate(vector<int>& nums)
    {
        unordered_set<int>s;
        int i=0,n = nums.size();

        for(; i<n; i++)
        {
            if(s.find(nums[i]) != s.end())
                break;
            else
                s.insert(nums[i]);
        }
        
        return nums[i];
    }
};