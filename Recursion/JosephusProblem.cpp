// There are n people standing in a circle (numbered clockwise 1 to n) waiting to be executed. The counting begins at point 1 in the circle and proceeds around the circle in a fixed direction (clockwise). In each step, a certain number of people are skipped and the next person is executed. The elimination proceeds around the circle (which is becoming smaller and smaller as the executed people are removed), until only the last person remains, who is given freedom.
// Given the total number of persons n and a number k which indicates that k-1 persons are skipped and kth person is killed in circle. The task is to choose the place in the initial circle so that you are the last one remaining and so survive.
// Consider if n = 5 and k = 2, then the safe position is 3.
// Firstly, the person at position 2 is killed, then person at position 4 is killed, then person at position 1 is killed. Finally, the person at position 5 is killed. So the person at position 3 survives.

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int print(vector<int> v,int k,int start){
    if(v.size()==1){
        return v[0];
    }
    start =  (start+k)%v.size();
    v.erase(v.begin()+start);
    return print(v,k,start);
}
 
int main(){
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++)
        v[i]=i+1;
    int start = 0;
    cout<<print(v,k-1,start);
    return 0;
}