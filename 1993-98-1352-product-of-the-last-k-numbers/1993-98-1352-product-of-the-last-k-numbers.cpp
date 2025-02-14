class ProductOfNumbers {
    vector<int> products;
    int product = 1;

public:
    ProductOfNumbers() {
        
    }
    
    void add(int num) {
        if(num == 0){
            products.clear();
            product = 1;
        }
        else{
            product *= num;
            products.push_back(product);
        }
    }
    
    int getProduct(int k) {
        if(products.size() < k) return 0;
        else if(products.size() == k) return products.back();
        else return products.back() / products[products.size() - k - 1];
    }
};

/**
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */