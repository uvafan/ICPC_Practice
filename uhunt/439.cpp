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

int dr[] = {-1,1,-2,2,-1,1,-2,2};
int dc[] = {-2,-2,-1,-1,2,2,1,1};

int main(){
    string a,b;
    int i,j;
    while(cin>>a>>b){
        ii s = ii(a[0]-'a',a[1]-'1');
        ii t = ii(b[0]-'a',b[1]-'1');
        queue<ii> q;
        vi dist(64,-1);
        dist[s.first*8+s.second]=0;
        q.push(s);
        while(q.size()){
            ii u=q.front(); q.pop();
            if(u==t)break;
            int d = dist[u.first*8+u.second]; 
            repr(i,0,8){
                int nr = u.first+dr[i];
                int nc = u.second+dc[i];
                if(nr<0||nr>7||nc<0||nc>7)
                    continue;
                if(dist[nr*8+nc]==-1){
                    dist[nr*8+nc]=d+1;
                    q.push(ii(nr,nc));
                }
            }
        }
        cout<<"To get from "<<a<<" to "<<b<<" takes "<<dist[t.first*8+t.second]<<" knight moves."<<endl;
    }
    return 0;
}
