class Solution 
{
public:
    vector<vector<char>> b;
    vector<string> ans;
    string s;
    int m, n;
    void exist(string words)
    {
        s=words;
        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(dfs(i,j,0))
                {
                    ans.push_back(s);
                    return;
                }
            }
        }
    }

    bool dfs(int x, int y,int d)
    {
        if(x<0 || x>=m ||y<0 || y>=n || s[d]!=b[x][y])
            return false;

        if(d==s.size()-1)
            return true;

        char current=b[x][y];
        b[x][y]='#';
        bool found=dfs(x+1,y,d+1) ||
                   dfs(x-1,y,d+1) ||
                   dfs(x,y+1,d+1) ||
                   dfs(x,y-1,d+1);
        b[x][y]=current;
        return found;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) 
    {
        b=board;
        m=board.size();
        n=board[0].size();
        for(int i=0; i<words.size(); i++) {
            exist(words[i]);
        }
        return ans;
    }
};