#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

int N;
vector<vector<double> > dp,d;

double solve(int a, int b){
    int v = 1 + max(a,b);
    if(v==N-1)
        return d[a][v] + d[v][b];
    if(dp[a][b] > -1)
        return dp[a][b];
    return dp[a][b] = min(d[a][v] + solve(v,b),d[v][b]+solve(a,v));
}

double dist(ii a, ii b){
    return hypot(abs(a.first-b.first),abs(a.second-b.second));
}

int main(){
    while(cin>>N){
        int i,j,k;
        vii ps;
        repr(i,0,N){
            cin>>j>>k;
            ps.pb(ii(j,k));
        }
        dp.assign(N,vector<double>(N,-1));
        d.assign(N,vector<double>(N,-1));
        repr(i,0,N){
            repr(j,0,N){
                d[i][j] = dist(ps[i],ps[j]);
            }
        }
        cout<<fixed<<setprecision(2)<<solve(0,0)<<endl;
    }
    return 0;
}
