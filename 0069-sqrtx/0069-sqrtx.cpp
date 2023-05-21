class Solution {
public:
    int mySqrt(int x) {
        // int res=0;
        // for(int i=1;i<=x;i++){
        //     if(i>x/i) break;
        //     res=i;
        // }
        // return res;
        
        int st=1,ed=x,mid,res;
        while(st<=ed){
            mid=st+(ed-st)/2;
            if(mid==x/mid) return mid;
            else if(mid>x/mid) ed=mid-1;
            else {
                st=mid+1;  
                res=mid;
            }          
        }
        return res;
    }
};