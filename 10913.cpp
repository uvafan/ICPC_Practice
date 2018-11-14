#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<ll> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

int N,k;
vector<vi> grid;
ll dp[75][75][6];
int ca;

ll solve(int r, int c, int neg){
    if(dp[r][c][neg]!=-1)
        return dp[r][c][neg];
    int i;
    if(r==N-1){
        ll sum=0;
        int j=neg;
        repr(i,c,N){
            sum+=grid[r][i];
            if(grid[r][i]<0)
                j++;
            if(j>k)
                return dp[r][c][neg]=-INF;
        }
        return dp[r][c][neg]=sum;
    }
    ll ans = -INF;
    ll sum=0;
    int choice=-1;
    int j=neg;
    repr(i,c,N){
        sum+=grid[r][i];
        if(grid[r][i]<0)
            j++;
        if(j>k)
            break;
        ll s = solve(r+1,i,j);
        if(s>-INF){
            if(sum+s>ans){
                choice=i;
                ans = sum+s;
            }
        }
    }
    sum=0;
    j=neg;
    for(i=c;i>-1;i--){
        sum+=grid[r][i];
        if(grid[r][i]<0)
            j++;
        if(j>k)
            break;
        ll s = solve(r+1,i,j);
        if(s>-INF){
            if(sum+s>ans){
                ans = sum+s;
                choice=i;
            }
        }
    }
    return dp[r][c][neg]=ans;
}

int main(){
    int i,j;
    ll n;
    int m;
    ca=0;
    while(cin>>N>>k&&N){
        ca++;
        grid.assign(N,vi(N,0));
        repr(i,0,75)
            repr(j,0,75)
                repr(m,0,6)
                    dp[i][j][m]=-1;
        repr(i,0,N){
            repr(j,0,N){
                cin>>n;
                grid[i][j]=n;
            }
        }
        ll ans = solve(0,0,0);
        if(ans==-INF)
            cout<<"Case "<<ca<<": impossible"<<endl;
        else
            cout<<"Case "<<ca<<": "<<ans<<endl;
    }
    return 0;
}
