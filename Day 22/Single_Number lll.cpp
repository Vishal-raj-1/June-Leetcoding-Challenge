class Solution
{
public:
    vector<int> singleNumber(vector<int>& nums)
    {
        //Xor of all element
        int Xor = nums[0];

        //To divide vector in two part
        //one have this set bit another one doesn't
        int rightSetBit;
        int n = nums.size();

        for(int i=1; i<n; i++)
            Xor ^= nums[i];

        rightSetBit = Xor & ~(Xor - 1);

        vector<int>ans(2);
        for(int i=0; i<n; i++)
        {
            if(nums[i] & rightSetBit)
                ans[0] ^= nums[i];
            else
                ans[1] ^= nums[i];
        }
        return ans;
    }
};
