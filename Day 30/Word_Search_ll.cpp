class Solution
{
public:
    bool check(vector<vector<char>>& board,int i,int j,int row,int col,int index,string word)
    {
        if(index == word.size())
            return true;

        if(i < 0 || j < 0 || i >= row || j >= col || board[i][j] == '#' || board[i][j] != word[index])
            return false;

        char temp = board[i][j];
        board[i][j] = '#';

        bool found = check(board,i+1,j,row,col,index+1,word) || check(board,i,j+1,row,col,index+1,word) ||
                     check(board,i-1,j,row,col,index+1,word) || check(board,i,j-1,row,col,index+1,word);

        board[i][j] = temp;

        return found;
    }

    vector<string> findWords(vector<vector<char>>& board,vector<string>& words)
    {
        int row = board.size();
        int col = board[0].size();
        int ws = words.size();

        unordered_set<string> ans;

        for(int i=0; i<row; i++)
        {
            for(int j=0; j<col; j++)
            {
                for(int k=0; k<ws; k++)
                {
                    if(board[i][j] == words[k][0] && check(board,i,j,row,col,0,words[k]))
                      {
                         //insert element if it doesnt exist in set
                          ans.insert(words[k]);
                      }
                }
            }
        }
        //copy the content of set
        vector<string>v(ans.begin(),ans.end());
        
        return v;
    }
};
