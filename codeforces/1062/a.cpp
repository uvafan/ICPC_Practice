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
    vi nums;
    int N,i,j,k;
    cin>>N;
    int last=0;
    int seq=0;
    int ans=0;
    repr(i,0,N){
        cin>>j;
        nums.pb(j);
        if(last==j-1){
            seq++;
        }
        else{
            ans = max(seq-1,ans);
            seq=0;
        }
        last=j;
    }
    if(last==1000){
        seq++;}
    cout<<max(ans,seq-1)<<endl;
    return 0;
}
