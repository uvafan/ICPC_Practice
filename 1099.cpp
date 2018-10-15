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

int N,W,H;
vi size;
int dp[101][(1<<15)-1];

int solve(int w, int mask){
    //d(w);d(mask);
    if(dp[w][mask]!=-1)
        return dp[w][mask];
    int i,j;
    int sum=0;
    vi satisfied;
    repr(i,0,N){
        if((1<<i)&mask){
            sum+=size[i];
            satisfied.pb(i);
        }
    }
    int ns=satisfied.size();
    //d(ns);
    if(ns==1){
        dp[w][mask]=1;
        return 1;
    }  
    int h=sum/w;
    int on;
    repr(on,1,(1<<ns)-1){
        //d(on);
        int mask0=mask;
        int mask1=mask;
        int s0=sum;
        repr(i,0,ns){
            int pnum=satisfied[i];
            if((1<<i)&on){
                s0-=size[pnum];
                mask0=mask0&(~(1<<pnum));
                //d(mask0);
            }
            else{
                mask1=mask1&(~(1<<pnum));
                //d(mask1);
            }
        }
        //d(s0);d(mask0);d(mask1);
        if(s0%w==0){
            if(solve(w,mask0)&&solve(w,mask1)){
                dp[w][mask]=1;
                return 1;
            }
        }
        if(s0%h==0){
            if(solve(s0/h,mask0)&&solve((sum-s0)/h,mask1)){
                dp[w][mask]=1;
                return 1;
            }
        }
    }
    dp[w][mask]=0;
    return 0;
}

int main(){
    int ca,i,j,k;
    ca=0;
    while(cin>>N&&N){
        ca++;
        cout<<"Case "<<ca<<": ";
        cin>>W>>H;
        size.assign(N,0);
        int sum=0;
        repr(i,0,N){
            cin>>j;
            size[i]=j;
            sum+=j;
        }
        if(sum!=W*H){
            cout<<"No"<<endl;
            continue;
        }
        repr(i,0,101){
            repr(j,0,1<<15){
                dp[i][j]=-1;
            }
        }
        int ans = solve(W,(1<<N)-1);
        if(ans)
            cout<<"Yes"<<endl;
        else
            cout<<"No"<<endl;
    }
    return 0;
}
