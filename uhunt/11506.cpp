#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int MAX_V=98;
int res[98][98], mf, f, s, t, V, E;
vi p;

void augment(int v, int minEdge){
    if (v==s) { f = minEdge; return; }
    else if (p[v] != -1) { augment(p[v], min(minEdge, res[p[v]][v]));
        res[p[v]][v] -= f; res[v][p[v]] += f; } 
}

int main(){
    mf=0;
    s=0;
    while(cin>>V && cin>>E){
        if(!V&&!E)
            break;
        mf=0;
        for(int i=0;i<MAX_V;i++){
            for(int j=0;j<MAX_V;j++){
                res[i][j]=0;
            }
        }
        t=V-1;
        vi cost(V,0);
        int i,c;
        for(int j=0;j<V-2;j++){
            cin>>i>>c;
            cost[i-2] = c;
        }
        int u,v,w;
        while(E--){
            cin>>u>>v>>w;
            res[u-1][v-1] = w;
            res[v-1][u-1] = w;
        }
        for(int i=1;i<V-1;i++){
            res[i][i+V-1] = cost[i-1];
            res[i+V-1][i] = cost[i-1];
            for(int j=0;j<V*2-1;j++){
                if(res[i][j] && j != i+V-1){
                    res[i+V-1][j] = res[i][j];
                    res[i][j]=0;
                }
            }
        }
        while(1){
            f=0;
            vi dist(MAX_V,INF); dist[s] = 0; queue<int> q; q.push(s);
            p.assign(MAX_V, -1);
            while(!q.empty()){
                int u = q.front(); q.pop();
                if (u==t) break;
                for(int v=0;v<MAX_V;v++)
                    if(res[u][v]>0 && dist[v]==INF)
                        dist[v] = dist[u]+1, q.push(v), p[v]=u;
            }
            augment(t,INF);
            if(f==0) break;
            mf+=f;
        }
        cout<<mf<<endl;
    }
    return 0;
}
