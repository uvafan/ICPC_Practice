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

int N,M;
double dists[16][16];
double best[(1<<17)-1];

void solve(int mask,double d){
    if(best[mask]==-1||best[mask]>d){
        best[mask]=d;
    }
    else
        return;
    if(mask==(1<<N)-1){
        return;
    }
    int i,j;
    int f=0;
    repr(i,0,N){
        if(!(mask&(1<<i))){
            f=i;
            break;
        }
    }
    i=f;
    mask=mask|(1<<i);
    repr(j,i+1,N){
        if(!(mask&(1<<j)))
            solve(mask|(1<<j),d+dists[i][j]);
    }
}

int main(){
    int ca=0;
    while(cin>>M&&M){
        ca++;
        int i,j,k;
        vii coords;
        N=M*2;
        string s;
        repr(i,0,N){
            cin>>s>>j>>k;
            coords.pb(ii(j,k));
        }
        repr(i,0,N){
            repr(j,i+1,N){
                double dist = hypot(coords[i].first-coords[j].first,coords[i].second-coords[j].second);
                dists[i][j]=dist;
            }
        }
        repr(i,0,1<<N){
            best[i]=-1;
        }
        solve(0,0);
        cout<<"Case "<<ca<<": "<<fixed<<setprecision(2)<<best[(1<<N)-1]<<endl;
    }
    return 0;
}
