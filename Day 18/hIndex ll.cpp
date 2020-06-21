class Solution
{
public :
    int hIndex(vector<int>&citations)
    {
        int Len = citations.size();

        for(int i=0; i<Len; i++)
        {
            if(citations[i] >= Len-i)
                return Len-i;
        }

        return 0;
    }
}