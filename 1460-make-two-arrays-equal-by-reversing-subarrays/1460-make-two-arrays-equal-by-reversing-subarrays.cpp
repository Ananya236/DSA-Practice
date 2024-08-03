class Solution {
public:
    bool canBeEqual(vector<int>& target, vector<int>& arr) {
        unordered_map<int,int> freq;
        for(int num: target)
            freq[num]++;
        
        for(int num: arr){
            if(freq.find(num) == freq.end()) return false;
            freq[num]--;
            if(freq[num]==0) freq.erase(num);
        }
        
        return !freq.size();
    }
};