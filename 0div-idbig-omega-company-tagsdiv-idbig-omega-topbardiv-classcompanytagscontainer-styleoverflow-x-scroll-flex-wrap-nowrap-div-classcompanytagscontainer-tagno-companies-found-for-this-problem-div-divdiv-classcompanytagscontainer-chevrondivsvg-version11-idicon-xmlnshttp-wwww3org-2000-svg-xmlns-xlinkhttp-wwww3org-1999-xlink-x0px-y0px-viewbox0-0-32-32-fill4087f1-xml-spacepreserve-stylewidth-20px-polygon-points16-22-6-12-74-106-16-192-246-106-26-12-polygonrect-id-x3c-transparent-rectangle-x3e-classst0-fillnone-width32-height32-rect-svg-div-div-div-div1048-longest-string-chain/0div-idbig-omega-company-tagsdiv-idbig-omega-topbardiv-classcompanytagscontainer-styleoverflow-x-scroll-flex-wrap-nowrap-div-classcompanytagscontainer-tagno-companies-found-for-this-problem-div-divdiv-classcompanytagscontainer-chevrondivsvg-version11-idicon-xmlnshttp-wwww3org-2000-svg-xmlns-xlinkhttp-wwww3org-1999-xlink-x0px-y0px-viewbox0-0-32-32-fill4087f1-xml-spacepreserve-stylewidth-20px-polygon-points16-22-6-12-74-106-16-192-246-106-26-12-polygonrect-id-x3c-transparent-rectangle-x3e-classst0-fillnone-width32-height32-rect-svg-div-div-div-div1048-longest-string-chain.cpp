class Solution {
public:
    static bool compare(string &w1, string &w2){
        return (w1.length()<w2.length());
    }
    
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> chain;
        int res = 0;
        
        sort(words.begin(), words.end(), compare);
        
        for(string w: words){
            for(int i=0;i<w.length();i++){
                string predecessor = w.substr(0,i)+w.substr(i+1);
                chain[w] = max(chain[w], chain[predecessor]+1);
            }
            res = max(res, chain[w]);
        }
        
        return res;
    }
};