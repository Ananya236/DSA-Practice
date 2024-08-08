class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> res;
        int left = cStart,right = cStart+1,top = rStart,bottom=rStart+1;
        while(left >= 0 || right < cols || top >= 0 || bottom < rows){
            if(top >= 0) for(int i=max(0,left); i<=min(cols-1,right-1) ; i++) 
                res.push_back({top,i});

            left--;

            if(right < cols) for(int i=max(0,top); i<=min(rows-1,bottom-1); i++)
                res.push_back({i,right});
            
            top--;

            if(bottom < rows) for(int i=min(cols-1,right); i>=max(0,left+1); i--)
                res.push_back({bottom,i});
            
            right++;

            if(left >= 0) for(int i=min(rows-1,bottom); i>=max(0,top+1); i--)
                res.push_back({i,left});
            
            bottom++;
        }
        return res;
    }
};