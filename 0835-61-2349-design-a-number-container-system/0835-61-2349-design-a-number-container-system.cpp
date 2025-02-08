class NumberContainers {
public:
    unordered_map<int,int> container;
    unordered_map<int,priority_queue<int,vector<int>,greater<int>>> numberIndex;

    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        numberIndex[number].push(index);
        container[index] = number;
    }
    
    int find(int number) {
        auto numberIndices = numberIndex[number];
        while(!numberIndices.empty() && container[numberIndices.top()] != number) 
            numberIndices.pop();
        return numberIndices.empty() ? -1 : numberIndices.top();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */