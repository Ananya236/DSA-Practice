class Solution {
public:
    vector<int> queryResults(int limit, vector<vector<int>>& queries) {
        unordered_map<int,int> ballColor, colorCnt;
        vector<int> result;
        for(auto query: queries){
            int ball = query[0], color = query[1];
            if(ballColor.find(ball) != ballColor.end()){
                int prevColor = ballColor[ball];
                colorCnt[prevColor]--;
                if(colorCnt[prevColor] == 0)
                    colorCnt.erase(prevColor);
            }
            ballColor[ball] = color;
            colorCnt[color]++;
            result.push_back(colorCnt.size());
        }

        return result;
    }
};