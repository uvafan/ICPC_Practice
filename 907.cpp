#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1000000000

int memo[602][301];
int adjMat[602][602];
int N;

int go(int cur, int days_left){
    if(days_left<0) return INF;
    if(cur==N-1) return 0;
    if(memo[cur][days_left] > -1) return memo[cur][days_left];
    int ans = INF;
    for(int v=0;v<N;v++){
        if(!adjMat[cur][v])
            continue;
        int next = go(v,days_left-1);
        next = max(next,adjMat[cur][v]);
        if(next < ans){
            ans = next;
        }
    }
    return memo[cur][days_left]=ans;
}

int main(){
    int K,d,i;
    while(cin>>N>>K){
        K++;
        N+=2;
        for(i=0;i<N;i++){
            for(int j=0;j<=K;j++){
                memo[i][j] = -1;
            }
        }
        for(i=0;i<N;i++){
            for(int j=0;j<N;j++){
                adjMat[i][j]=0;
            }
        }
        for(i=1;i<N;i++){
            cin>>d;
            for(int j=0;j<i;j++){
                adjMat[j][i] = adjMat[j][i-1]+d;
            }
        }
        cout<<go(0,K)<<endl;
    }
    return 0;
}
