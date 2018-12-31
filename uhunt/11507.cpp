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
    while(cin>>N&&N){
        string s;
        vector<string> v;
        repr(i,0,N-1){cin>>s;v.pb(s);}
        string ret="+x";
        for(i=0;i<N-1;i++){
            s=v[i];
            if(s=="No")
                continue;
            if(ret=="+x")
                ret=s;
            else if(ret=="-x"){
                ret[0] = s[0]=='-'?'+':'-';
                ret[1] = s[1];
            }
            else if(ret[1]==s[1]){
                if(ret[0]==s[0]){
                    ret="-x";
                }
                else{
                    ret="+x";
                }
            }
        }
        cout<<ret<<endl;
    }
    return 0;
}
