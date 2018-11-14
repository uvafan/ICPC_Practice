#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9

struct Edge {
    int u,v;
    ll cap,flow;
    Edge(){}
    Edge(int u, int v, ll cap): u(u), v(v), cap(cap), flow(0) {}
};

struct Dinic {
    int N;
    vector<Edge> E;
    vector<vi> g;
    vi dis,pt;

    Dinic(int N): N(N), E(0), g(N), dis(N), pt(N) {}

    void addEdge(int u, int v, ll cap){
        if(u!=v){
            E.pb(Edge(u,v,cap));
            g[u].pb(E.size()-1);
            E.pb(Edge(v,u,0));
            g[v].pb(E.size()-1);
        }
    }

    bool bfs(int S, int T){
        queue<int> q({S});
        fill(dis.begin(),dis.end(),N+1);
        dis[S]=0;
        while(!q.empty()){
            int u =q.front();q.pop();
            if(u==T)break;
            for(int k: g[u]){
                Edge &e = E[k];
                if(e.flow<e.cap&&dis[e.v]>dis[e.u]+1){
                    dis[e.v]=dis[e.u]+1;
                    q.push(e.v);
                }
            }
        }
        return dis[T] != N+1;
    }

    ll dfs(int u, int T, ll flow=-1){
        if(u==T||!flow) return flow;
        for(int &i = pt[u]; i<g[u].size(); ++i){
            Edge &e = E[g[u][i]];
            Edge &oe = E[g[u][i]^1];
            if(dis[e.v]==dis[e.u]+1){
                ll amt = e.cap-e.flow;
                if(flow!=-1&&amt>flow) amt=flow;
                if(ll pushed = dfs(e.v,T,amt)){
                    e.flow+=pushed;
                    oe.flow-=pushed;
                    return pushed;
                }
            }
        }
        return 0;
    }

    ll maxFlow(int S, int T){
        ll total=0;
        while(bfs(S,T)){
            fill(pt.begin(),pt.end(),0);
            while(ll flow = dfs(S,T))
                total += flow;
        }
        return total;
    }
};

int main(){
    return 0;
}
