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
    int N,i,j;
    while(cin>>N&&N){
        vi f(100,0);
        repr(i,0,N){
            cin>>j;
            f[j]++;
        }
        string ret="";
        repr(i,0,100){
            repr(j,0,f[i]){
                ret += to_string(i)+' ';
            }
        }
        cout<<ret.substr(0,ret.size()-1)<<endl;
    }
    return 0;
}
