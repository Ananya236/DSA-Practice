class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        int n = order.size();
        
        vector<char> hash(n);
        
        for(int i=0;i<n;i++)
            hash[order[i]-'a'] = i+97;
        
        for(int i=0;i<words.size();i++){
            string temp="";
            for(char l: words[i])
                temp+=hash[l-'a'];
            words[i]=temp;
        }
        
        for(int i=1; i<words.size(); i++){
            if(words[i]<words[i-1]) return false;
        }
        
        return true;
    }
};