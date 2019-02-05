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

ii M[2001][2001];

int main(){
    double d;
    int N;
    int i,j,k;
    while(cin>>d>>N){
        int W = floor(d);
        repr(i,0,2001)repr(j,0,2001)M[i][j]=ii(-INF,-1);
        M[0][0]=ii(0,-1);
        vi v,w;
        v.pb(0);w.pb(0);
        repr(i,0,N){
            cin>>j>>k;
            v.pb(j);w.pb(k);
        }
        int besti=-1; int bestj=-1; int maxVal = -1;
        repr(i,1,N+1){
            repr(j,0,W+1){
                if(w[i]>j){
                    M[i][j]=M[i-1][j];
                }
                else{
                    int option = M[i-1][j-w[i]].first+v[i];
                    if(option>M[i-1][j].first){
                        M[i][j] = ii(option,i);
                    }
                    else{
                        M[i][j]=M[i-1][j];
                    }
                    if(M[i][j].first>maxVal){
                        maxVal=M[i][j].first;
                        besti=i;
                        bestj=j;
                    }
                }
            }
        }
        vi ans;
        i=besti;
        j=bestj;
        while(j>0){
            ans.pb(i-1);
            int temp=i;
            //d(i);d(j);d(M[i][j].first);d(M[i][j].second);
            i=M[i-1][j-w[i]].second;
            j-=w[temp];
        }
        cout<<ans.size()<<endl;
        repr(i,0,ans.size()){
            cout<<ans[i]<<' ';
        }
        cout<<endl;
    }
    
    return 0;
}
