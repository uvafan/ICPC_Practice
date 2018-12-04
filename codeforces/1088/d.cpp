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
    ll a=0;
    ll b=0;
    ll i,j,k,ag,ans;
    ll MAX=30;
    ll c = (1<<MAX)-1;
    ll d = (1<<MAX)-1;
    i=MAX-1;
    while(i>-1){
        cout<<"? "<<a<<' '<<b<<endl;fflush(stdout);
        cin>>ag;
        if(!ag){
            while(i>-1){
                c=a;
                d=b+(1<<i);
                cout<<"? "<<c<<' '<<d<<endl;fflush(stdout);
                cin>>ans;
                if(ans==1){
                    a+=(1<<i);
                    b+=(1<<i);
                }
                i--;
            }
        }
        while(i>-1){
            c-=(1<<i);
            d-=(1<<i);
            cout<<"? "<<c<<' '<<d<<endl;fflush(stdout);
            cin>>ans;
            if(ans==ag){
                if(ag==1){
                    a+=(1<<i);
                    c+=(1<<i);
                }
                else{
                    b+=(1<<i);
                    d+=(1<<i);
                }
                i--;
                break;
            }
            else{
                cout<<"? "<<a<<' '<<b+(1<<i)<<endl;fflush(stdout);
                cin>>ans;
                if(ans==1){
                    a+=(1<<i);
                    b+=(1<<i);
                    c+=(1<<i);
                    d+=(1<<i);
                }
            }
            i--;
        }
    }
    cout<<"! "<<a<<' '<<b<<endl;
    fflush(stdout);
    return 0;
}
