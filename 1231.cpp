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
        int t,h,f;
        cin>>t>>h>>f;
        vector<vi> acorns(t,vi(h,0));
        int i,j,k;
        repr(i,0,t){
            cin>>j;
            while(j--){
                cin>>k;
                acorns[i][k-1]++;
            }
        }
        vi dp(h,0);
        repr(i,0,t){
            dp[h-1] = max(dp[h-1],acorns[i][h-1]);
        }
        for(i=h-2;i>=0;i--){
            repr(j,0,t){
                int bestOpt = acorns[j][i+1];
                if(i+f<h)
                    bestOpt = max(bestOpt,dp[i+f]);
                acorns[j][i]+=bestOpt;
                dp[i] = max(dp[i],acorns[j][i]);
            }
        }
        cout<<dp[0]<<endl;
    }
    return 0;
}
