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
    int V,E,H,a,b,i,j,k;
    while(cin>>V&&V){
        vi hotel_num(V,0);
        cin>>H;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        vector<vi> adjList2(H+2,vi(0,0));
        vi hotels;
        repr(i,0,H){
            cin>>j;j--;
            hotel_num[j]=i+1;
            hotels.pb(j);
        }
        cin>>E;
        while(E--){
            cin>>a>>b>>k;a--;b--;
            adjList[a].pb(ii(b,k));
            adjList[b].pb(ii(a,k));
        }
        priority_queue<ii,vii,greater<ii> > pq;
        vi dist(V,INF);
        pq.push(ii(0,0));dist[0]=0;
        int ans=-1;
        while(!pq.empty()){
            ii info = pq.top(); pq.pop();
            int d = info.first; int u = info.second;
            if(d>dist[u])
                continue;
            if(u==V-1){
                ans=0;
                break;
            }
            for(ii inf: adjList[u]){
                int v = inf.first; int w = inf.second;
                if((d+w<dist[v])&&(d+w<=600)){
                    dist[v] = d+w;
                    pq.push(ii(d+w,v));
                }
            }
        }
        if(!ans){
            cout<<0<<endl;
            continue;
        }
        repr(i,0,H){
            priority_queue<ii,vii,greater<ii> > pq;
            vi dist(V,INF);
            pq.push(ii(0,hotels[i]));dist[hotels[i]]=0;
            while(!pq.empty()){
                ii info = pq.top(); pq.pop();
                int d = info.first; int u = info.second;
                if(d>dist[u])
                    continue;
                if(hotel_num[u]&&u!=hotels[i]){
                    adjList2[hotel_num[u]].pb(i+1);
                    adjList2[i+1].pb(hotel_num[u]);
                }
                if(!u){
                    adjList2[0].pb(i+1);
                    adjList2[i+1].pb(0);
                }
                if(u==V-1){
                    adjList2[H+1].pb(i+1);
                    adjList2[i+1].pb(H+1);
                }
                for(ii inf: adjList[u]){
                    int v = inf.first; int w = inf.second;
                    if((d+w<dist[v])&&(d+w<=600)){
                        dist[v] = d+w;
                        pq.push(ii(d+w,v));
                    }
                }
            }
        }
        queue<int> q;
        q.push(0);
        dist.assign(H+2,INF);
        dist[0]=0;
        while(!q.empty()){
            int u = q.front();q.pop();
            if(u==H+1){
                ans = max(dist[u]-1,0);
                break;
            }
            for(int v: adjList2[u]){
                if(1+dist[u]<dist[v]){
                    q.push(v);
                    dist[v]=dist[u]+1;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
