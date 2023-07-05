class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        unordered_map<char,int> m;
        int res=0;
        // for(int i=0;i<n-res;i++){
        //     for(int j=i;j<n;j++){
        //         if(st.count(s[j])) {
        //             int len = st.size();
        //             if(len>res) res=len;
        //             st.clear();
        //             break;
        //         }
        //         st.insert(s[j]);
        //     }
        // }
        // int len = st.size();
        // if(len>res) res=len;
        // return res;
        
        int count = 0;
        for(int st=0,i=0;i<n;i++){
            if(m[s[i]]>0) count++;
            m[s[i]]++;
            
            while(count>0){              
                m[s[st]]--;
                if(m[s[st]]==1) count--;
                st++;
            }
            
            int curr = i-st+1;
            if(curr>res) res=curr;
        }
        
        return res;
    }
};