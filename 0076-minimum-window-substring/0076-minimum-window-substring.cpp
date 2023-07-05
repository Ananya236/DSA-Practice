class Solution {
public:
    string minWindow(string s, string t) {
        if(s==t) return s;
        
        int n1 = s.size(), n2 = t.size();
        if(n1<n2) return "";
        
        unordered_map<char,int> m;
        for(auto i: t) m[i]++;
        
        int start=-1, window=INT_MAX;
        
        for(int beg=0,ed=0; ed<n1; ed++){            
            if(m[s[ed]]>0) n2--; 
            m[s[ed]]--;
            
            while(n2==0){
                int currWin = ed-beg+1;
                if(currWin < window) {
                    window=currWin;
                    start=beg;
                }
                
                m[s[beg]]++;
                if(m[s[beg]]>0) n2++;
                beg++;
            }
        }
        if(start==-1) return "";        
        return s.substr(start,window);
    }
};