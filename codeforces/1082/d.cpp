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
    int V,i,j,k;
    cin>>V;
    vii nodes;
    repr(i,0,V){
        cin>>j;
        nodes.pb(ii(j-2,i+1));
    }
    sort(nodes.begin(),nodes.end());
    vii edges;
    int latch=V-1;
    bool can=true;
    int diam=2;
    int s=V-1;
    repr(i,2,V){
        ii n = nodes[i];
        if(n.first==-1){
            while(nodes[latch].first==0)
                latch--;
            if(nodes[latch].first==-1){
                can=false;
                break;
            }
            else{
                nodes[latch].first--;
                edges.pb(ii(n.second,nodes[latch].second));
            }
        }
        else if(i<V-1){
            s=min(s,i);
            diam++;
            edges.pb(ii(n.second,nodes[i+1].second));
        }
    }
    if(!can)
        cout<<"NO"<<endl;
    else{
        edges.pb(ii(nodes[0].second,nodes[s].second));
        edges.pb(ii(nodes[1].second,nodes[V-1].second));
        cout<<"YES "<<diam<<endl<<V-1<<endl;
        for(ii e: edges){
            cout<<e.first<<' '<<e.second<<endl;
        }
    }
    return 0;
}
