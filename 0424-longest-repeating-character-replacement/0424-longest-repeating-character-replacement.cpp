class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxFreq = 0, maxLen = 0;
        int st=0, ed=0, n=s.size();
        vector<int> freq(26,0);
        
        while(ed<n){
            maxFreq = max(maxFreq, ++freq[s[ed]-'A']);
            if(ed-st+1 <= maxFreq + k){   // valid window
                maxLen = max(maxLen, ed-st+1);
            }
            else if(ed-st+1 > maxFreq + k){ // invalid window just after valid one
                freq[s[st]-'A']--;
                st++;
            }
            ed++;
        }
        
        return maxLen;
    }
};