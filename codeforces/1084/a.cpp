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

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    int ret=INF;
    vi nums;
    int i,j,k;
    cin>>k;
    repr(i,0,k){
        cin>>j;
        nums.pb(j);
    }
    int x,a,b;
    repr(x,0,k){
        int cum=0;
        repr(a,0,k){
            int e = abs(x-a)*2+a*2+x*2;
            cum+=e*nums[a];
        }
        ret = min(cum,ret);
    }
    cout<<ret<<endl;
    return 0;
}
