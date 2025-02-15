class Solution {
public:
    bool partitionPossible(string square, int sum){
        if(square.length()==0) return sum == 0;

        int tempSum = 0;
        for(int i=0; i<square.length(); i++){
            tempSum = tempSum*10 + (square[i]-'0');
            if(tempSum > sum) break;
            bool res = partitionPossible(square.substr(i+1), sum-tempSum);
            if(res) return res;
        }

        return false;
    }

    int punishmentNumber(int n) {
        int resSum = 0;
        for(int i=1; i<=n; i++){
            int square = i*i;
            if(partitionPossible(to_string(square), i))
                resSum += square;
        }
        return resSum;
    }
};