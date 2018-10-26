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

ll _sieve_size;
bitset<10000010> bs;
vector<ll> primes;
vector<ll> aprimes;

int bsearch(ll q){
    //d(q);
    int lo=0;
    int hi=aprimes.size()-1;
    while(lo<hi){
        int mid = (lo+hi)/2+1;
        //d(mid);
        if(q>aprimes[mid]){
            lo = mid;
        }
        else{
            hi = mid-1;
        }
    }
    //d(lo);
    return lo;
}

void sieve(ll upperbound){
    _sieve_size = upperbound+1;
    bs.set();
    bs[0] = bs[1] = 0;
    for(ll i=2; i<=_sieve_size; i++)if(bs[i]){
        for(ll j=i*i; j<=_sieve_size; j+=1) bs[j]=0;
        primes.pb(i);
    }
}

int main(){
    sieve(1000000);
    //cout<<"b"<<endl;
    for(ll p: primes){
        ll ap = p*p;
        while(ap<(ll)1e12){
            aprimes.pb(ap);
            ap*=p;
        }
    }
    //cout<<"b"<<endl;
    sort(aprimes.begin(),aprimes.end());
    int N;
    ll a,b;
    cin>>N;
    while(N--){
        cin>>a>>b;
        int c = bsearch(a);
        int d = bsearch(b+1);
        cout<<d-c+((c==0&&aprimes[0]>=a)?1:0)<<endl;
    }
    return 0;
}
