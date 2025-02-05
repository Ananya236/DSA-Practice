class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        if(s1 == s2) return true;
        
        int c1=-1,c2=-1;

        for(int i=0; i<s1.size(); i++){
            if(s1[i]!=s2[i]){
                if(c1>=0 && c2>=0) return false;
                else if(c1==-1) c1 = i;
                else c2 = i;
            }
        }

        return c1>=0 && c2>=0 && s1[c1]==s2[c2] && s1[c2]==s2[c1];
    }
};