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
    vi solved(26,0);
    vi time(26,0);
    while(cin>>j&&j!=-1){
        char c;
        string s;
        cin>>c>>s;
        if(s=="right"){
            solved[c-'A']=1;
            time[c-'A']+=j;
        }
        else{
            time[c-'A']+=20;
        }
    }
    int s,t;
    s=0;t=0;
    repr(i,0,26){
        s+=solved[i];
        if(solved[i])
            t+=time[i];
    }
    cout<<s<<' '<<t;
    return 0;
}
