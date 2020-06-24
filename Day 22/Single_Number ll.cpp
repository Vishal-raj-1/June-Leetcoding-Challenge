class Solution
{
public:
    int singleNumber(vector<int>& nums)
    {
        int bits[32] = {0};
        int result = 0;

        for(int i=0; i<32; i++)
        {
            for(int n : nums)
            {
                bits[i] += (n >> i)&1;
                bits[i] %= 3;
            }
        }

        for(int i=0; i<32; i++)
            result |= (bits[i]<<i);

        return result;
    }
};
