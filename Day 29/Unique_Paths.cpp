class Solution
{
public:
    int uniquePaths(int m, int n)
    {
         int paths[n][m];

        //last row
        for(int i=0; i<n; i++)
            paths[i][m-1] = 1;

        //last coloumn
        for(int j=0; j<m; j++)
            paths[n-1][j] = 1;

        for(int i=n-2; i>=0; i--)
            for(int j=m-2; j>=0; j--)
                paths[i][j] = paths[i+1][j] + paths[i][j+1];
            
        return paths[0][0];
    }
};
