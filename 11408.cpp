#include <bits/stdc++.h>
using namespace std; 
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vll;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

ll _sieve_size;
bitset<10000010> bs;
vi primes;

void sieve(ll upperbound){
    _sieve_size = upperbound+1;
    bs.set();
    bs[0]=bs[1]=0;
    for(ll i=2;i<=_sieve_size;i++){if(bs[i]){
        for(ll j=i*i;j<=_sieve_size;j+=i)bs[j]=0;
        primes.push_back((int)i);
    }
    }
}

bool isPrime(ll N){
    if(N<=_sieve_size) return bs[N];
    for(int i=0;i<(int)primes.size();i++)
        if(N%primes[i]==0)return false;
    return true;
}

ll primeFactors(int N){
    ll factors;
    int PF_idx=0,PF=primes[PF_idx];
    while(PF*PF<=N){
        while(N%PF==0){N/=PF;factors+=PF;}
        PF = primes[++PF_idx];
    }
    if(N!=1)factors+=N;
    return factors;
}

int main(){
    sieve(5000000);
    int i,j;
    int c=0;
    vll sump(5000000,0);
    vi ans(5000000,0);
    repr(i,2,5000001){
        if(!sump[i]){
            for(j=i;j<5000001;j+=i){
                sump[j]+=i;
            }
        }
        if(isPrime(sump[i])){
            c++;
        }
        ans[i]=c;
    }
    int k;
    while(cin>>i&&i){
        cin>>k;
        cout<<ans[k]-ans[i-1]<<endl;
    }
    return 0;
}
