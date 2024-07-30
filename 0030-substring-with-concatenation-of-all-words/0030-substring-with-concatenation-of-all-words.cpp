class Solution {
    std::unordered_map<std::string, unsigned int> map;
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        std::vector<int> result;
        unsigned int length = words[0].size();

        map.clear();
        for (const std::string& word : words)
            map[word]++;

        for (unsigned int offset = 0; offset < length; ++offset) {
            unsigned int size = 0;
            std::unordered_map<std::string, unsigned int> seen;
            for (unsigned int i = offset; i + length <= s.size(); i += length) {
                std::string sub = s.substr(i, length);

                auto itr = map.find(sub);
                if (itr == map.end()) {
                    seen.clear();
                    size = 0;
                    continue;
                }

                ++seen[sub];
                ++size;
                while (seen[sub] > itr->second) {
                    std::string first = s.substr(i - (size - 1) * length, length);
                    --seen[first];
                    --size;
                }
                
                if (size == words.size())
                    result.push_back(i - (size - 1) * length);
            }
        }

        return result;
    }
    
    vector<int> findSubstring1(string s, vector<string>& words) {
        vector<int> indexes;
        unordered_map<string, int> wordCount;
        
        for(auto word: words)
            wordCount[word]++;
        
        int n = words[0].size();
        
        for(int offset=0; offset<n; offset++){
            int windowWords = 0;
            unordered_map<string, int> foundWordCount;
            for(int i=offset; i<s.size(); i+=n){
                string curWord = s.substr(i,n);
                if(wordCount[curWord]){
                    foundWordCount[curWord]++;
                    windowWords++;
                    int startIndex = i - ((windowWords-1)*n);
                    while(foundWordCount[curWord]>wordCount[curWord]){
                        string startWord = s.substr(startIndex,n);
                        foundWordCount[startWord]--;
                        windowWords--;
                    }
                    if(windowWords==words.size()) indexes.push_back(startIndex);
                }else{
                    foundWordCount.clear();
                    windowWords=0;
                }
            }
        }
        
        return indexes;
    }
};