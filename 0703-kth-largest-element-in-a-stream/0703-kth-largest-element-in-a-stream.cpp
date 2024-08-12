class KthLargest {
private:
    priority_queue<int, vector<int>, greater<int>> minh;
    int k;
    
public:
    KthLargest(int k, vector<int>& nums) {
        this->k = k;
        for(int num: nums) add(num);
    }
    
    int add(int val) {
        if(minh.size()<k || minh.top()<val){
            minh.push(val);
            if(minh.size()>k) minh.pop();
        }
        return minh.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */