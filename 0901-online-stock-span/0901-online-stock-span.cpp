class StockSpanner {
public:
    stack<pair<int,int>> s;
    int size=0;
    
    StockSpanner() 
    {
        
    }
    
    int next(int price) 
    {
        int res=0;
        if(s.empty()) res=-1;
        else{
            if(s.top().first>price)
                res=s.top().second;
            else{
                while(!s.empty() && s.top().first<=price)
                    s.pop();
                if(s.empty()) res=-1;
                else res=s.top().second;
            }
        }
        s.push({price,size++});
        return size-res-1;;
    }
};


/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */