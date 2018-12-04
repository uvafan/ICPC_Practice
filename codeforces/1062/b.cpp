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

unordered_map<int,int> primeFactors(int N){
    unordered_map<int,int> freq;
    int PF_idx=0,PF=primes[PF_idx];
    while(PF*PF<=N){
        if(!(N%PF))freq[PF]=0;
        while(N%PF==0){N/=PF;freq[PF]++;}
        PF = primes[++PF_idx];
    }
    if(N!=1)freq[N]=1;
    return freq;
}

int main(){
    sieve(1000000);
    int n;
    cin>>n;
    unordered_map<int,int> freq = primeFactors(n);
    int num=1; int transforms=0;int offFlag=0;int last =-1;
    for(auto it: freq){
        num*=it.first;
        int cum=1;
        int count=1;
        while(cum<it.second){
            transforms=max(transforms,count);
            cum*=2;
            count++;
        }
        if(cum!=it.second||(last>-1&&it.second!=last))
            offFlag=1;
        last=it.second;
    }
    cout<<num<<" "<<transforms+offFlag<<endl;
    return 0;
}
