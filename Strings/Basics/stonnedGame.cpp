//#Codeforces
//#Stonned Game

//T is playing a game with his friend, HL.

// There are n piles of stones, the i-th pile initially has ai stones.

// T and HL will take alternating turns, with T going first. In each turn, a player chooses a non-empty pile and then removes a single stone from it. However, one cannot choose a pile that has been chosen in the previous turn (the pile that was chosen by the other player, or if the current turn is the first turn then the player can choose any non-empty pile). The player who cannot choose a pile in his turn loses, and the game ends.

// Assuming both players play optimally, given the starting configuration of t games, determine the winner of each game.

//eg:
//i/p- 
// 2 (No of games)
// 1 (No of piles for game 1)
// 2 (No of stones in each pile acc to index for game 1)
// 2 (No of piles for game 2)
// 1 1 (No of stones in each pile for game 2)
//o/p- 
// T
// HL

#include<bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

int main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;    
        vector<int> freq(n);
        for(int i=0;i<n;i++){
            cin>>freq[i];
        }
        if(n==1){
            cout<<"T\n";
            continue;
        }    
        sort(freq.begin(),freq.end(),greater<int>());
        if(freq[0]>freq[1])
        cout<<"T\n";
        else
        cout<<"HL\n";
    }
    return 0;
}