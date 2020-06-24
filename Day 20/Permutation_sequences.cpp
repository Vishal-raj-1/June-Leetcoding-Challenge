class Solution
{
public:
    string getPermutation(int n,int k)
    {
        int temp = 2;
        string num = "1";

        while(temp <= n)
        {
            num += temp + '0';
            temp++;
        }

        if(k == 1)
            return num;

        temp = 0;

        while(next_permutation(num.begin(),num.end()))
        {
            temp++;
            if(temp >= k-1)
                break;
        }
        
        return num;
    }
};
