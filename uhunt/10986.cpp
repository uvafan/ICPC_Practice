#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int N,i,j,a,b,V,E,s,t,ca;
    cin>>N;
    for(ca=1;ca<=N;ca++){
        cin>>V>>E>>s>>t;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        while(E--){
            cin>>a>>b>>j;
            adjList[a].push_back(ii(b,j));
            adjList[b].push_back(ii(a,j));
        }
        vi dist(V,INF);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        pq.push(ii(0,s));
        dist[s]=0;
        while(!pq.empty()){
            ii inf = pq.top(); pq.pop();
            int u = inf.second; int d = inf.first;
            if(u==t)break;
            if(d>dist[u])continue;
            for(i=0;i<adjList[u].size();i++){
                ii v = adjList[u][i];
                if(dist[u]+v.second<dist[v.first]){
                    dist[v.first] = dist[u] + v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }
        if(dist[t]==INF)cout<<"Case #"<<ca<<": unreachable"<<endl;
        else cout<<"Case #"<<ca<<": "<<dist[t]<<endl;
    }
    return 0;
}
