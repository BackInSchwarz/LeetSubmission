class StockSpanner {
public:
    vector<int> prices;
    vector<int> span;
    StockSpanner() {
        // vector<int> prices(0);
        // vector<int> span(0);
    }
    
    int next(int price) {
        // cout<<"current price is "<<price<<endl;
        prices.push_back(price);
        // auto it = span.end();
        // int ans = 0;

        int n = prices.size();
        span.push_back(1);
        if (n==1){

            return 1;
        } 
        // span.push_back(0);
        int last = n-1;
        int i = n-2;
        while(i>=0){
            // cout<<i<<""<<endl;
            if(prices[i]<=prices[last]){
                span[last]+=span[i];
            }
            i = i-span[i];
        }
        
        return span[span.size()-1];
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */