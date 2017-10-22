#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int n,k,i,j,a,b;
    while(cin>>n>>k){
        vi times(n,0);
        for(i=0;i<n;i++){
            cin>>a>>ws;
            times[i]=a;
            //cout << "time " << a;
        }
        vector<vii> adjList(n*100,vii(0,ii(0,0)));
        for(i=0;i<n;i++){
            for(j=i+1;j<n;j++){
                for(int m = 0; m<100;m++){
                    int u = i*100 + m;
                    int v = j*100 + m;
                    adjList[u].push_back(ii(v,60));
                    adjList[v].push_back(ii(u,60));
                }
            }
        }
        for(i=0;i<n;i++){
            vi floors;
            cin>>a;
            floors.push_back(a);
            //cout<<"b"<<endl;
            while(cin.peek()!='\n'){
                cin>>a;
                floors.push_back(a);
                //cout<< "floor " << a << " for el " << i << endl;
            }
            for(j=0;j<floors.size();j++){
                for(int m=j+1;m<floors.size();m++){
                    int u = i*100 + floors[j];
                    int v = i*100 + floors[m];
                    int w = (v-u)*times[i];
                    adjList[u].push_back(ii(v,w));
                    adjList[v].push_back(ii(u,w));
                }
            }
        }
        vi dist(n*100,INF);
        priority_queue<ii, vector<ii>, greater<ii> > pq;
        for(i=0;i<n;i++){
            pq.push(ii(0,i*100));
            dist[i*100]=0;
        }
        int ans = INF;
        while(!pq.empty()){
            ii inf = pq.top(); pq.pop();
            int u = inf.second; int d = inf.first;
            if(u%100==k){
                ans = d;
                break;
            }
            if(d>dist[u])continue;
            for(i=0;i<adjList[u].size();i++){
                ii v = adjList[u][i];
                if(d+v.second<dist[v.first]){
                    dist[v.first] = d + v.second;
                    pq.push(ii(dist[v.first],v.first));
                }
            }
        }
        if(ans==INF)cout<<"IMPOSSIBLE"<<endl;
        else cout<<ans<<endl;
    }
    return 0;
}
