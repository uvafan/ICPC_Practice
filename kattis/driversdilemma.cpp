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
    int best = -1;
    double mpg;
    double x,m,c;
    cin>>c>>x>>m;
    int i,j,k;
    repr(i,0,6){
        cin>>j>>mpg;
        double timeTaken = m/j;
        double gused = timeTaken * x + m/mpg;
        if(gused<c/2){
            best = j;
        }
    }
    if(best==-1){
        cout<<"NO"<<endl;
    }
    else{
        cout<<"YES "<<best<<endl;
    }
    return 0;
}
