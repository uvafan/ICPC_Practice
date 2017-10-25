#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int V,i,j;

bool conn(vector<vii> adjList, int s){
    vi dist(V,INF); dist[s]=0;
    for(i=0;i<V-1;i++)
        for(int u=0;u<V;u++)
            for(j=0;j<adjList[u].size();j++){
                ii v = adjList[u][j];
                dist[v.first] = min(dist[v.first],dist[u]+v.second);
            }
    return dist[V-1]<INF/2;
}

int main(){
    int N,E,x,y,t;
    while(1){
        cin>>V;
        if(V==-1)break;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        vi energies(V,0);
        for(i=0;i<V;i++){
            cin>>x>>y;
            energies[i]=x;
            while(y--){
                cin>>t;
                adjList[i].push_back(ii(t-1,0));
            }
        }
        for(i=0;i<V;i++){
            for(j=0;j<adjList[i].size();j++){
                adjList[i][j].second = -energies[adjList[i][j].first];
            }
        }
        vi dist(V,INF); dist[0]=0;
        for(i=0;i<V-1;i++)
            for(int u=0;u<V;u++)
                for(j=0;j<adjList[u].size();j++){
                    ii v = adjList[u][j];
                    dist[v.first] = min(dist[v.first],dist[u]+v.second);
                }
        bool poss = false;
        for(i=0;i<V;i++){
            if(poss)break;
            for(j=0;j<adjList[i].size();j++){
                ii v = adjList[i][j];
                if(dist[v.first]<INF/2&&conn(adjList,v.first)&&(dist[i]+v.second<dist[v.first])){
                    poss = true;
                    break;
                }
            }
        }
        if(poss||dist[V-1]<100)cout<<"winnable"<<endl;
        else cout<<"hopeless"<<endl;
    }
    return 0;
}
