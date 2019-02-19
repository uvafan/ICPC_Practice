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
    int N,i,j,k;
    cin>>N;
    while(N--){
        cin>>j>>k;
        int ret=0;
        repr(i,2,k+2){
            ret+=i;
        }
        cout<<j<<' '<<ret<<endl;
    }
    return 0;
}
