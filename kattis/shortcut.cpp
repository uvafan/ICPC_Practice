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
    int N;
    cin>>N;
    while(N--){
        int b,k,d;
        cin>>b>>k;
        int div = b-1;
        int ans = 1;
        for(int i=1;i*i<=div;i++){
            if(div%i==0){
                if(div/i<=k){
                    ans = max(ans,div/i);
                }
                if(i<=k){
                    ans = max(ans,i);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
