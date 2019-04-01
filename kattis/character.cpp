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

long long choose(int n, int i){
    long long ans = 1;
    int j;
    repr(j,n-i+1,n+1){
        ans*=j;
        ans/=(j-(n-i));
    }
    return ans;
}

int main(){
    int n;
    int i,j,k; 
    cin>>n;
    long long ans = 0;
    repr(i,2,n+1){
        ans += choose(n,min(i,n-i));
    }
    cout<<ans<<endl;
    return 0;
}
