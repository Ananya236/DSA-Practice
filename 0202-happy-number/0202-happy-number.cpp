class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int,int>m;
        while(n!=1){
            if(m.find(n)!=m.end()) return false;
            m[n]++;
            int curr = n;
            n=0;
            while(curr){
                int r = curr%10;
                curr/=10;
                n+=pow(r,2);
            }
        }
        return true;
    }
};