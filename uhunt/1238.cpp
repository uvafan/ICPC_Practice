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

int N;
bool vis[31][31][6001];
int sig[31];
int num[31];
bool used[6001];

void rec(int i, int open, int val){
    if(vis[i][open][val+3000])
        return;
    vis[i][open][val+3000]=true;
    if(i==N){
        used[val+3000]=true;
        return;
    }
    
    int nval = val+num[i]*sig[i]*((open%2==0)?1:-1);
    if(sig[i]==-1)
        rec(i+1,open+1,nval);
    if(open>0)
        rec(i+1,open-1,nval);
    rec(i+1,open,nval);
}

int main(){
    int n,i,j,k;
    while(cin>>n){
        repr(i,0,31){
            repr(j,0,31){
                repr(k,0,6001){
                    vis[i][j][k]=false;
                    used[k]=false;
                }
            }
        }
        num[0]=n;
        sig[0]=1;
        N=1;
        char c;
        while(cin.peek()!='\n'){
            cin>>c>>n;
            num[N]=n;
            if(c=='-')
                sig[N]=-1;
            else
                sig[N]=1;
            N++;
        }
        rec(0,0,0);
        int ans=0;
        repr(i,0,6001){
            ans += (used[i]?1:0);
        }
        cout<<ans<<endl;
    }
    return 0;
}
