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

typedef long long ll;

int main(){
    int Q;
    cin>>Q;
    ll j,k,a,b;
    int i;
    repr(i,0,Q){
        cin>>a>>b>>k;
        j=(a-b)*(k/2);
        if(k%2)
            j+=a;
        cout<<j<<endl;
    }
    return 0;
}
