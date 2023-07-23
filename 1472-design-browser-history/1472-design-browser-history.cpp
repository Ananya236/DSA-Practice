class BrowserHistory {
public:
    vector<string> history;
    int top,curr;
    
    BrowserHistory(string homepage) {
        history.resize(5001);
        curr=0; top=0;
        history[curr]=homepage;
    }
    
    void visit(string url) {
        curr++;
        top=curr;
        history[curr]=url;
    }
    
    string back(int steps) {
        curr-=steps;
        if(curr<0) curr=0;
        return history[curr];
    }
    
    string forward(int steps) {
        curr+=steps;
        if(curr>top) curr=top;
        return history[curr];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */