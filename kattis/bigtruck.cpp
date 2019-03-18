#include <bits/stdc++.h>
using namespace std;

typedef pair<int,int> ii;
typedef pair<ii,int> iii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define repr(i,l,r) for(int i=(l), _##i=(r); i<_##i; ++i)
#define d(arg) do {cerr << #arg << ": "; cerr << arg; cerr << endl;} while(0)
#define pb push_back
#define INF (int)1e9
#define EPS 1e-9


int main(){
    int V,i,j,k;
    cin>>V;
    vi items(V,0);
    repr(i,0,V){
        cin>>items[i];
    }
    int E;
    cin>>E;
    vector<vii> adjList(V,vii(0,ii(0,0)));
    repr(i,0,E){
        int w;
        cin>>j>>k>>w;
        j--;k--;
        adjList[j].pb(ii(k,w));
        adjList[k].pb(ii(j,w));
    }
    vii dist(V,ii(INF,INF));
    priority_queue<ii> pq;
    pq.push(ii(0,0));
    dist[0] = ii(0,items[0]);
    while(!pq.empty()){
        ii inf = pq.top(); pq.pop();
        int u = inf.second; int d = -inf.first;
        if(d>dist[u].first){
            continue;
        }
        //d(u);d(d);d(ite);
        for(ii next: adjList[u]){
            int v = next.first;
            int w = next.second;
            if(d+w<dist[v].first){
                dist[v] = ii(d+w,dist[u].second+items[v]);
                pq.push(ii(-d-w,v));
            }
            else if(d+w==dist[v].first){
                dist[v].second = max(dist[v].second,dist[u].second+items[v]);
            }
        }
    }
    if(dist[V-1].first==INF){
        cout<<"impossible"<<endl;
    }
    else{
        cout<<dist[V-1].first<<' '<<dist[V-1].second<<endl;
    }
    return 0;
}
