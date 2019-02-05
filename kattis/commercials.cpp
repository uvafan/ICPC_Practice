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

int main(){
    int N,P,i,j,k;
    cin>>N>>P;
    int best=0;
    int cur=0;
    repr(i,0,N){
        cin>>j;
        cur = max(0,cur+j-P);
        best = max(best,cur);
    }
    cout<<best<<endl;
    return 0;
}
