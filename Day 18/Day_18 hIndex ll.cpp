class Solution
{
public :
    int hIndex(vector<int>&citations)
    {
        int len = citations.size();
     
        int low = 0,high = len-1,mid;
        
        while(low <= high)
        {
            mid = (high+low)/2;
            
            if(citations[mid] < len-mid)
                low = mid+1;
            else
                high = mid-1;
        }
        
        return len-low;
    }
};