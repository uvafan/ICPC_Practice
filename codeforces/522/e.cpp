#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

unordered_map<int,int,custom_hash> m;

vi weights;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int N,i,j,k;
    cin>>N;
    map<int,int> freq;
    set<int> wset;
    int sum=0;
    repr(i,0,N){
        cin>>j;weights.pb(j);freq[j]++;sum+=j;
    }
    int dp[N+1][N*100+1];
    repr(i,0,N+1)repr(j,0,100*N+1){dp[i][j]=0;}
    dp[0][0]=1;
    repr(i,0,N){
        d(i);
        for(k=i+1;k>0;k--){
            repr(j,0,sum+1){
                dp[k][j] = min(((j>=weights[i]&&k>0)?dp[k-1][j-weights[i]]:0) + dp[k][j],2);
                d(k);d(j);d(dp[k][j]);
            }
        }
    }
    int best=1;
    int cum=1;
    int count=0;
    for(auto e: freq){
        count++;
        for(int n=e.second;n>best;n--){
            bool ok = dp[n][e.first*n]<2;
            /*
            for(auto e2: freq){
                if(e.first==e2.first)
                    continue;
                if(dp[n-1][e.first*n-e2.first]){
                    d(n);d(e.first);d(e2.first);
                    ok=false;
                    break;
                }
            }*/
            if(ok){
                best=n;break;
            }
        }
    }
    if(count==1||count==2)
        cout<<N<<endl;
    else
        cout<<best<<endl;
    return 0;
}
