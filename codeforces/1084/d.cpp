#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef pair<ll,ll> pll;

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
vector<vii> adjList;
vector<ll> gas;
vi vis;
int V;
ll ans;

ll solve(int u, int p){
    int j,k;
    ll ret = gas[u];
    ans = max(ans,ret);
    repr(j,0,adjList[u].size()){
        int v = adjList[u][j].first;
        if(v==p)
            continue;
        ll c = solve(v,u)-adjList[u][j].second;
        ans = max(ans,ret+c);
        ret = max(ret,gas[u]+c);
    }
    return ret;
}

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>V;
    int i;
    ll a,b,c;
    repr(i,0,V){
        cin>>a;    
        gas.pb(a);
    }
    adjList.assign(V,vii(0,ii(0,0)));
    repr(i,0,V-1){
        cin>>a>>b>>c;a--;b--;
        adjList[a].pb(ii(b,c));
        adjList[b].pb(ii(a,c));
    }
    ans=0;
    solve(0,-1);
    cout<<ans<<endl;
    return 0;
}
