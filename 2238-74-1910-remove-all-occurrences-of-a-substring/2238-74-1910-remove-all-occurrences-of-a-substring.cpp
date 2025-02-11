class Solution {
public:
    string removeOccurrences(string s, string part) {
        string stack;
        int n = part.size();
        char back = part.back();

        for(char c: s){
            stack.push_back(c);

            if(c==back && stack.size()>=n){
                int currPartStart = stack.size()-n;
                if(stack.substr(currPartStart) == part)
                    stack.erase(currPartStart);
            }
        }

        return stack;
    }
};