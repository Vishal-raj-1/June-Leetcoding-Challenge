class Solution
{
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon)
    {
        int row = dungeon.size();
        int col = dungeon[0].size();

        vector<vector<int> > sol(row, vector<int>(col));

        sol[row-1][col-1] = dungeon[row-1][col-1] > 0 ? 1 : 1 - dungeon[row-1][col-1];

        //Last column
        for(int i=row-2; i>=0; i--)
            sol[i][col-1] = max(sol[i+1][col-1] - dungeon[i][col-1], 1);

        //Last row
        for(int j=col-2; j>=0; j--)
            sol[row-1][j] = max(sol[row-1][j+1] - dungeon[row-1][j], 1);

        //Rest
        for(int i=row-2; i>=0; i--)
            for(int j=col-2; j>=0; j--)
                sol[i][j] = max(min(sol[i][j+1],sol[i+1][j])-dungeon[i][j],1);

        return sol[0][0];
    }
};