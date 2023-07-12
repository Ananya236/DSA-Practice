class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        vector<char> hash(26);
        
        for(int i=0;i<order.length();i++)
            hash[order[i]-97]=i+97;
        
        
        for(int i=0;i<words.size();i++)
        {
            string s=words[i];
            string temp;
            for(auto ch:s)
                temp.push_back(hash[ch-97]);
            words[i]=temp;
        }
        
       for(int i=1;i<words.size();i++)
           if(words[i]<words[i-1])
               return false;
        
        return true;
    }
};