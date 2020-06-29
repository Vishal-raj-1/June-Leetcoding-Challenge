class Solution
{
public:
    int numSquares(int n)
    {
        vector<int>dp(n+1,n);
        dp[0] = 0,dp[1] = 1;

        int Sq = (int)sqrt(n);
        for(int i=2; i<=n; i++)
        {
            //if it is perfect square
            if(Sq*Sq == n)
            {
                dp[i] = 1;
                continue;
            }
            
            for(int j=1; j*j <= i; j++)
                dp[i] = min(dp[i],dp[i - j*j] + 1);
        }

        return dp[n];
    }
};
