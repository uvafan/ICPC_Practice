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
    vector<double> anthonyps(1001,0);
    vector<double> coraps(1001,0);
    int i,j,k,n,m;
    double d;
    cin>>n>>m;
    coraps[m]=1;
    repr(i,0,n+m-1){
        cin>>d;
        repr(j,1,1001){
            double p = d*coraps[j];
            coraps[j-1]+=p;
            coraps[j]-=p;
        }
    }
    cout<<coraps[0]<<endl;
    return 0;
}
