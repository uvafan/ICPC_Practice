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

int V,E,dfs_counter,numSCC;
vi dfs_num,dfs_low,S,vis;
vector<vi> adjList;
vector<set<int> > adjList2;
vector<set<int> > sccs;

void tarjanSCC(int u){
    dfs_low[u]=dfs_num[u]=dfs_counter++;
    S.pb(u);
    vis[u]=1;
    int j;
    repr(j,0,(int)adjList[u].size()){
        int v = adjList[u][j];
        if(dfs_num[v]==-1)
            tarjanSCC(v);
        if(vis[v])
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u]==dfs_num[u]){
        numSCC++;
        while(1){
            int v = S.back(); S.pop_back(); vis[v]=0;
            sccs[numSCC-1].insert(v);
            if(u==v)
                break;
        }
    }
}

int main(){
    int i,j,k,N;
    cin>>N;
    while(N--){
        cin>>V>>E;
        S.clear();
        set<int> s;
        sccs.assign(V,s);
        dfs_num.assign(V,-1); dfs_low.assign(V,0); vis.assign(V,0);
        adjList.assign(V,vi(0,0));
        dfs_counter=0;
        numSCC=0;
        repr(i,0,E){
            cin>>j>>k;j--;k--;
            adjList[j].pb(k);
        }
        repr(i,0,V){
            if(dfs_num[i]==-1)
                tarjanSCC(i);
        }
        adjList2.assign(numSCC,s);
        repr(i,0,numSCC){
            for(int u: sccs[i]){
                dfs_low[u]=i;
            }
        }
        repr(i,0,numSCC){
            for(int u: sccs[i]){
                repr(j,0,(int)adjList[u].size()){
                    int v=adjList[u][j];
                    if(dfs_low[v]!=dfs_low[u])
                        adjList2[i].insert(dfs_low[v]);
                }
            }
        }
        vi clique_size(numSCC,0);
        vi best(numSCC,0);
        vi indegree(numSCC,0);
        int ans=0;
        repr(u,0,numSCC){
            clique_size[u] = sccs[u].size();
            best[u]=clique_size[u];
            for(int v: adjList2[u]){
                indegree[v]++;
            }
        }
        queue<int> q;
        repr(i,0,numSCC){
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty()){
            int u=q.front();q.pop();
            ans = max(ans,best[u]);
            for(int v: adjList2[u]){
                indegree[v]--;
                best[v]=max(best[u]+clique_size[v], best[v]);
                if(!indegree[v])
                    q.push(v);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
