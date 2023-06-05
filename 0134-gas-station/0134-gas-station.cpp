class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int st=0,currCost=0,n=cost.size(),tg=0;
        for(int i=0;i<n;i++){
            tg+=gas[i]-cost[i];
            currCost+= gas[i]-cost[i];
            if(currCost<0){
                st=i+1;
                currCost=0;
            }
        }
        if(currCost<0 || tg<0) return -1;
        return st;
    }
};