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
string l,g;
int N,K;

int main(){
    ios::sync_with_stdio(false),cin.tie(0);
    cin>>N>>K>>l>>g;
    ll provL=0;
    ll provG=0;
    ll provB=0;
    ll provN=0;
    ll ans=0;
    int i,j;
    if(l[0]==g[0]){
        provN=1;
        ans=1;
    }
    else{
        provL=1;
        provG=1;
        ans = min(K,2);
    }
    repr(i,1,N){
        ll amount = provG+provL+provB+provN;
        if(amount>=K){
            ans+=K;
            continue;
        }
        char le = l[i]; char gr = g[i];
        provB*=2;
        if(le=='a'&&gr=='a'){
            provB+=provG;
            //provG+=provN;
        }
        if(le=='a'&&gr=='b'){
            provB+=(provG+provL);
            provG+=provN;
            provL+=provN;
            provN=0;
        }
        if(le=='b'&&gr=='b'){
            provB+=provL;
            //provL+=provN;
        }
        amount = provG+provL+provB+provN;
        ans += (amount>K)?K:amount;
    }
    cout<<ans<<endl;
    return 0;
}
