#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (double)1e9
#define EPS 1e-9

typedef double ll;
//typedef long long ll;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<ll,ll> pll;

struct MinCostMaxFlow {
    int N;
    vvl cap,flow,cost;
    vi found;
    vl dist,pi,width;
    vii dad;

    MinCostMaxFlow(int N): 
        N(N), cap(N, vl(N)), flow(N, vl(N)), cost(N, vl(N)),
        found(N), dist(N), pi(N), width(N), dad(N) {}

    void addEdge(int u, int v, ll cap, ll cost){
        this->cap[u][v]=cap;
        this->cost[u][v]=cost;
    }

    void relax(int s, int k, ll cap, ll cost, int dir){
        ll val = dist[s]+pi[s]-pi[k]+cost;
        if(cap&&val<dist[k]){
            dist[k]=val;
            dad[k]=ii(s,dir);
            width[k]=min(cap,width[s]);
        }
    }

    ll dijkstra(int s, int t){
        fill(found.begin(),found.end(),0);
        fill(dist.begin(),dist.end(),INF);
        fill(width.begin(),width.end(),0);
        dist[s]=0;
        width[s]=INF;
        int k;
        while(s != -1){
            int best=-1;
            found[s]=1;
            repr(k,0,N){
                if(found[k])continue;
                relax(s,k,cap[s][k]-flow[s][k],cost[s][k],1);
                relax(s,k,flow[k][s],-cost[k][s],-1);
                if(best==-1||dist[k]<dist[best])best=k;
            }
            s=best;
        }
        repr(k,0,N)
            pi[k] = min(pi[k]+dist[k],INF);
        return width[t];
    }

    pll mf(int s, int t){
        ll totflow=0,totcost=0;
        while(ll amt = dijkstra(s,t)){
            totflow+=amt;
            for(int x=t;x!=s;x=dad[x].first){
                if(dad[x].second==1){
                    flow[dad[x].first][x]+=amt;
                    totcost+=cost[dad[x].first][x];
                }
                else{
                    flow[x][dad[x].first]-=amt;
                    totcost-=cost[x][dad[x].first];
                }
            }
        }
        return pll(totflow,totcost);
    }
};

int main(){
    int N,M,i,j;
    double k;
    while(cin>>N>>M&&N){
        MinCostMaxFlow mcmf(M+N+2);
        repr(i,0,N){
            mcmf.addEdge(0,i+1,1,0);
        }
        repr(i,0,M){
            mcmf.addEdge(N+1+i,N+1+M,1,0);
        }
        repr(i,0,N){
            repr(j,0,M){
                cin>>k;
                mcmf.addEdge(i+1,N+1+j,1,k);
            }
        }
        pll ans = mcmf.mf(0,M+N+1);
        cout<<fixed<<setprecision(2)<<ans.second/ans.first<<endl;
    }
    return 0;
}
