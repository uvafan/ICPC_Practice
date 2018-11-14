#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int N,V,E,x,y,t,i,j;
    cin>>N;
    while(N--){
        cin>>V>>E;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        while(E--){
            cin>>x>>y>>t;
            adjList[x].push_back(ii(y,t));
        }
        vi dist(V,INF); dist[0]=0;
        for(i=0;i<V-1;i++)
            for(int u=0;u<V;u++)
                for(j=0;j<adjList[u].size();j++){
                    ii v = adjList[u][j];
                    dist[v.first] = min(dist[v.first],dist[u]+v.second);
                }
        bool poss = false;
        for(i=0;i<V;i++)
            for(j=0;j<adjList[i].size();j++){
                ii v = adjList[i][j];
                if(dist[i]+v.second<dist[v.first])
                    poss = true;
            }
        if(poss)cout<<"possible"<<endl;
        else cout<<"not possible"<<endl;
    }
    return 0;
}
