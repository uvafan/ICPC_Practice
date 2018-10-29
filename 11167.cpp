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

    vector<vii> getAns(vi ints){
        vii empty;
        vector<vii> ans(100,empty);
        int u,v,i;
        vi offset(201,0);
        repr(u,1,101){
            repr(i,0,g[u].size()){
                Edge e = E[g[u][i]];
                int s = ints[e.v-101];
                if(e.flow>0){
                    if(e.flow==e.cap){
                        ans[u-1].pb(ii(s,s+e.flow));
                    }
                    else{
                        int off = offset[e.v-101];
                        if(off+e.flow>e.cap){
                            ans[u-1].pb(ii(s+off,s+e.cap));
                            ans[u-1].pb(ii(s,s+e.flow+off-e.cap));
                            off+=e.flow+1;
                        }
                        else{
                            ans[u-1].pb(ii(s+off,off+s+e.flow));
                            off+=e.flow+1;
                        }
                        offset[e.v-101] = off%e.cap;
                    }
                }
            }
        }
        vector<vii> ret(100,empty);
        repr(i,0,100){
            sort(ans[i].begin(),ans[i].end());
            ii tA = ii(-1,-1);
            int j;
            repr(j,0,ans[i].size()){
                ii n = ans[i][j];
                if(n.first==tA.second)
                    tA.second=n.second;
                else{
                    if(tA.first!=-1)
                        ret[i].pb(tA);
                    tA = n;
                }
            }
            if(tA.first!=-1)
                ret[i].pb(tA);
        }
        return ret;
    }

};

int main(){
    int N,M,i,j,k,v,a,b;
    int ca=0;
    while(cin>>N&&N){
        ca++;
        cin>>M;
        set<int> s;
        s.insert(0);
        s.insert(50000);
        Dinic dinic(303);
        ll target=0;
        vii monkeyints;
        repr(i,0,N){
            cin>>v>>a>>b;
            target+=v;
            dinic.addEdge(0,i+1,v);
            s.insert(a);s.insert(b);
            monkeyints.pb(ii(a,b));
        }
        vi ints;
        for(int intEdge: s){
            ints.pb(intEdge);
        }
        repr(i,0,ints.size()-1){
            int s=ints[i]; int e=ints[i+1];
            dinic.addEdge(101+i,302,M*(e-s));
            repr(j,0,N){
                ii mint = monkeyints[j];
                if(mint.first<=s&&mint.second>=e){
                    dinic.addEdge(j+1,101+i,e-s);
                }
            }
        }
        ll mf = dinic.maxFlow(0,302);
        cout<<"Case "<<ca<<": ";
        if(mf==target){
            cout<<"Yes"<<endl;
            vector<vii> ans = dinic.getAns(ints);
            int idx=0;
            for(vii vints: ans){
                idx++;
                if(idx>N)
                    break;
                cout<<vints.size();
                for(ii interval: vints){
                    cout<<" ("<<interval.first<<","<<interval.second<<")";
                }
                cout<<endl;
            }
        }
        else
            cout<<"No"<<endl;
    }
    return 0;
}
