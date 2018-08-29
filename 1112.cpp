#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int N,i,j,a,b,C,E,T,M;
    cin>>N;
    int count = 0;
    while(N--){
        cin>>C>>E>>T>>M;
        if(count)cout<<endl;
        count++;
        vi dist(C,INF);
        vector<vii> adjList(C,vii(0,ii(0,0)));
        int t;
        while(M--){
            cin>>a>>b>>t;
            a--; b--;
            adjList[b].push_back(ii(a,t));
        }
        dist[E-1]=0;
        priority_queue<ii,vector<ii>,greater<ii> > pq;
        pq.push(ii(0,E-1));
        while(!pq.empty()){
            ii inf = pq.top(); pq.pop();
            int u = inf.second; int d = inf.first;
            if(d>dist[u])continue;
            for(i=0;i<adjList[u].size();i++){
                ii v = adjList[u][i];
                int vtx = v.first; int w = v.second;
                if(dist[u]+w<dist[vtx]){
                    dist[vtx] = dist[u] + w;
                    pq.push(ii(dist[vtx],vtx));
                }
            }
        }
        int ret = 0;
        for(i=0;i<C;i++){
            if(dist[i]<=T)ret++;
        }
        cout<<ret<<endl;
    }
    return 0;
}
