#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>
#include <string>
using namespace std;

#define rep(i, a, b) for (int i = a; i < (b); i++)
//typedef vector<int> vi;


//string ret[1000];
//vector<char> ret[1000];
int scr[1000][1000];
int par[1000][1000];
int R, C;

float find_neighboor_avg(int i, int j){
int res = 0;
int count = 0;
for (int rr = i-1; rr >=0; rr--) {
    if (par[rr][j] == 1) {
        count +=1; 
        res += scr[rr][j];
        break;
    }
}

for (int rr = i+1; rr < R; rr++) {
    if (par[rr][j] == 1) {
        count +=1; 
        res += scr[rr][j];
        break;
    }
}

for (int cc = j-1; cc >=0; cc--) {
    if (par[i][cc] == 1) {
        count +=1; 
        res += scr[i][cc];
        break;
    }
}

for (int cc = j+1; cc < C; cc++) {
    if (par[i][cc] == 1) {
        count +=1; 
        res += scr[i][cc];
        break;
    }
}
return count >0? res / count : 0;

}

void rsolve(int casenum) {
    // rep(i, 0, 1000) memset(scr[i], -1, sizeof(scr[i]));
    // rep(i, 0, 1000) memset(par[i], 0, sizeof(scr[i]));   
    cin >> R >> C;
    for (int i=0; i <R; i++){
        for (int j=0;j <C; j++)
        {
            cin >> scr[i][j];
            par[i][j] = 1;
        }
            
    }
    bool round_end = false;
    int int_lev_round;
    int int_lev_sum = 0;
    int round = 0;
    while (!(round_end)){
        round += 1;
        int elim = 0;
        int_lev_round = 0;
        for (int i=0; i <R; i++){
            for (int j=0;j <C; j++)
            {
                if (par[i][j] > 0 ){
                    int_lev_round += scr[i][j];
                    float navg = find_neighboor_avg(i,j);
                    if (navg > scr[i][j]) {
                        par[i][j] = 0;
                        elim += 1;
                    }
                }
            
            }
            
        }
        if (elim == 0) round_end = true;
        int_lev_sum += int_lev_round;
    }

    cout << "Case #" << casenum << ": " << int_lev_sum << "\n";
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    int t;
    //for (int i =0 ; i <sizeof(ret); i++) ret[i]= "";
    cin >> t;

    string str;
    for(int casenum = 1; casenum <= t; casenum++) {
        

       rsolve(casenum);
       
    }
      // cout << "Case #" << casenum << ": ";
    
  

}