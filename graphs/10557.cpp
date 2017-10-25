#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int V,i,j;

int main(){
    int N,E,x,y,t;
    while(1){
        cin>>V;
        if(V==-1)break;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        vector<vi> adjListB(V,vi(0,0));
        vi energies(V,0);
        for(i=0;i<V;i++){
            cin>>x>>y;
            energies[i]=x;
            while(y--){
                cin>>t;
                adjList[i].push_back(ii(t-1,0));
                adjListB[t-1].push_back(i);
            }
        }
        for(i=0;i<V;i++){
            for(j=0;j<adjList[i].size();j++){
                adjList[i][j].second = energies[adjList[i][j].first];
            }
        }
        vi dist(V,-INF); dist[0]=100;
        for(i=0;i<V-1;i++)
            for(int u=0;u<V;u++){
                if(dist[u]<0)continue;
                for(j=0;j<adjList[u].size();j++){
                    ii v = adjList[u][j];
                    dist[v.first] = max(dist[v.first],dist[u]+v.second);
                }
            }
        bool poss = false;
        //cout<<"b"<<endl;
        vi conn(V,0);
        queue<int> q;
        q.push(V-1);
        conn[V-1]=1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(i=0;i<adjListB[u].size();i++){
                int v = adjListB[u][i];
                if(!conn[v]){
                    conn[v] = 1;
                    q.push(v);
                }
            }
        }
        for(i=0;i<V;i++){
            if(poss)break;
            for(j=0;j<adjList[i].size();j++){
                ii v = adjList[i][j];
                if(dist[i]>0&&(dist[i]+v.second>dist[v.first])&&conn[v.first]){
                    //cout<<"di = "<<dist[i] << " od = " << dist[v.first] << " nd = "<<dist[i]+v.second<<" ";
                    poss = true;
                    break;
                }
            }
        }
        //if(poss)cout<<"poss ";
        if(poss||dist[V-1]>0)cout<<"winnable"<<endl;
        else cout<<"hopeless"<<endl;
    }
    return 0;
}
