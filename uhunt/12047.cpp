#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int T,V,E,s,t,p,a,b,w,i,j;
    cin>>T;
    while(T--){
        cin>>V>>E>>s>>t>>p;
        s--;
        t--;
        vector<vii> adjList(V,vii(0,ii(0,0)));
        vector<vii> adjListB(V,vii(0,ii(0,0)));
        for(i=0;i<E;i++){
            cin>>a>>b>>w;
            adjList[a-1].push_back(ii(b-1,w));
            adjListB[b-1].push_back(ii(a-1,w));
        }
        //cout<<"b"<<endl;
        vi dists(V,INF);
        dists[s]=0;
        priority_queue<ii,vector<ii>,greater<ii> > pq;
        pq.push(ii(0,s));
        while(!pq.empty()){
            ii inf = pq.top(); pq.pop();
            int u = inf.second; int d = inf.first;
            if(d>dists[u])continue;
            for(i=0;i<adjList[u].size();i++){
                ii v = adjList[u][i];
                if(d+v.second<dists[v.first]){
                    dists[v.first] = d + v.second;
                    pq.push(ii(dists[v.first],v.first));
                }
            }
        }        
        vi distt(V,INF);
        distt[t]=0;
        pq.push(ii(0,t));
        while(!pq.empty()){
            ii inf = pq.top(); pq.pop();
            int u = inf.second; int d = inf.first;
            if(d>distt[u])continue;
            for(i=0;i<adjListB[u].size();i++){
                ii v = adjListB[u][i];
                if(d+v.second<distt[v.first]){
                    distt[v.first] = d + v.second;
                    pq.push(ii(distt[v.first],v.first));
                }
            }
        } 
        //cout<<"b"<<endl;
        int maxT = -INF;
        for(i=0;i<adjList.size();i++){
            for(j=0;j<adjList[i].size();j++){
                if(adjList[i][j].second>maxT&&adjList[i][j].second+dists[i]+distt[adjList[i][j].first]<=p)
                    maxT = adjList[i][j].second;
            }
        }
        if(maxT==-INF)cout<<"-1"<<endl;
        else cout<<maxT<<endl;
    }
    return 0;
}
