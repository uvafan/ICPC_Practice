#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int N,V,E,x,y,t,i,j,q;
    int count = 0;
    while(cin>>V){
        count++;
        vi juncts(V,0);
        for(i=0;i<V;i++){
            cin>>juncts[i];
        }
        cin>>E;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        while(E--){
            cin>>x>>y;
            int w = pow(juncts[y-1]-juncts[x-1],3);
            //cout<<w<<endl;
            adjList[x-1].push_back(ii(y-1,w));
        }
        cout<<"Set #"<<count<<endl;
        vi dist(V,INF); 
        if(dist.size())dist[0]=0;
        for(i=0;i<V-1;i++)
            for(int u=0;u<V;u++)
                for(j=0;j<adjList[u].size();j++){
                    ii v = adjList[u][j];
                    dist[v.first] = min(dist[v.first],dist[u]+v.second);
                }
        vi poss(V,0);
        for(i=0;i<V;i++)
            for(j=0;j<adjList[i].size();j++){
                ii v = adjList[i][j];
                if(dist[i]+v.second<dist[v.first]){
                    poss[v.first] = 1;
                }
            }
        for(i=0;i<V;i++){
            if(!poss[i])continue;
            for(j=0;j<adjList[i].size();j++){
                ii v = adjList[i][j];
                poss[v.first] = 1;
            }
        }
        cin>>q;
        while(q--){
            cin>>t;
            if(dist[t-1]>=3&&!poss[t-1]&&dist[t-1]!=INF&&dist[t-1]<INF/2)cout<<dist[t-1]<<endl;
            else cout<<"?"<<endl;
        }
    }
    return 0;
}
