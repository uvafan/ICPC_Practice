#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int MAX_N=100;
int res[100][100], mf, f, s, t;
vi p;

void augment(int v, int minEdge){
    if (v==s) { f = minEdge; return; }
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f; } 
}

int main(){
    mf = 0;
    int c,N,a,b,band;
    string line;
    int netNum=0;
    while(cin>>N && N){
        netNum++;
        mf=0;
        for(int i=0;i<MAX_N;i++){
            for(int j=0;j<MAX_N;j++){
                res[i][j]=0;
            }
        }
        cin>>s>>t>>c;
        s--;t--;
        while(c--){
            cin>>a>>b>>band;
            res[a-1][b-1]+=band;
            res[b-1][a-1]+=band;
        }
        while(1){
            f=0;
            vi dist(N,INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(N, -1);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if (u==t) break;
                for(int v=0;v<N;v++)
                    if(res[u][v]>0 && dist[v]==INF)
                        dist[v] = dist[u]+1, q.push(v), p[v]=u;
            }
            augment(t,INF);
            if(f==0) break;
            mf+=f;
        }
        cout << "Network " << netNum << endl << "The bandwidth is " << mf << "." << endl << endl;
    }
    return 0;
}
