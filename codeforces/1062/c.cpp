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

int N,Q;
string s;
vi sum;
ll tn[100002];
ll MOD=1000000007;

void filltn(){
    ll cum=1;
    int i;
    repr(i,0,100002){
        tn[i]=cum;
        cum = (cum*2)%MOD;
    }
}

ll getans(int i,int j){
    int ones = sum[j]-(i==0?0:sum[i-1]);
    int zeros = j-i-ones+1;
    ll ans = tn[ones+zeros]-1-(tn[zeros]-1);
    return (ans<0?(ans+MOD)%MOD:ans%MOD);
}

int main(){
    cin>>N>>Q;
    cin>>s;
    int i,j,k;
    j=0;
    filltn();
    repr(i,0,N){
        j+=(int(s[i])-'0');
        sum.pb(j);
    }
    while(Q--){
        cin>>j>>k;j--;k--;
        cout<<getans(j,k)<<endl;
    }
    return 0;
}
