#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <set>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

void dfs(int u);
vi dfs_num;
set<ii> moves;
int e,o,R,C,M,N,numWT;

int main(){
    int k;
    cin >> k;
    for(int n = 1; n <= k; n++){
        e = 0;
        o = 0;
        dfs_num.clear();
        moves.clear();
        int i;
        cin >> R >> C >> M >> N;
        moves.insert(make_pair(M,N));
        moves.insert(make_pair(-1*M,N));
        moves.insert(make_pair(M,-1*N));
        moves.insert(make_pair(-1*M,-1*N));
        moves.insert(make_pair(N,M));
        moves.insert(make_pair(-1*N,M));
        moves.insert(make_pair(N,-1*M));
        moves.insert(make_pair(-1*N,-1*M));

        //0 = unvisited, 1 = visited, -1 = water
        for(i = 0; i < R*C; i++)
            dfs_num.push_back(0);
        cin >> numWT;
        while(numWT--){
            int r,c;
            cin >> r >> c;
            dfs_num[r*C+c] = -1;
        }
        dfs(0);
        printf("Case %d: %d %d\n",n,e,o); 
    }
    return 0;
}

void dfs(int u){
    if(dfs_num[u] == 1)return;
    dfs_num[u] = 1;
    int r = u / C;
    int c = u % C;
    int possibleMoves = 0;
    for(set<ii>::iterator it = moves.begin(); it != moves.end(); it++){
        ii move = *it;
        int rNext = r + move.first;
        int cNext = c + move.second;
        if(rNext < 0 || rNext >= R || cNext < 0 || cNext >= C){
            continue;
        }
        int nextU = rNext*C+cNext;
        if(dfs_num[nextU] > -1){
            possibleMoves++;
            dfs(nextU);
        }
    }
    if(possibleMoves%2==0)
        e++;
    else
        o++;
}
