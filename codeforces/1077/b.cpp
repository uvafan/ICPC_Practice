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
    int N,j;
    cin>>N;
    int ans=0;
    int last=-1;int lastl=-1;
    while(N--){
        cin>>j;
        if(j&&last==0&&lastl==1){
            ans++;
            j=0;
        }
        lastl=last;
        last=j;
    }
    cout<<ans<<endl;
    return 0;
}
