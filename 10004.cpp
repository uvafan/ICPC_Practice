#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

int main(){
    int nodes,edges,i,j;
    while(1){
        cin >> nodes;
        if(!nodes)break;
        cin >> edges;
        vector<vi> adjList;
        vi toAdd;
        for(i=0;i<nodes;i++)adjList.push_back(toAdd);
        vi color(nodes,INF);
        for(i=0;i<edges;i++){
            int a,b;
            cin >> a >> b;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        queue<int> q;
        q.push(0);
        color[0]=0;
        bool ret = true;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(i=0;i<adjList[u].size();i++){
                int v = adjList[u][i];
                if(color[v]==INF){
                    color[v] = 1 - color[u];
                    q.push(v);
                }
                else if(color[v] == color[u]){
                    ret = false;
                    break;
                }
            }
        }
        if(ret) cout<<"BICOLORABLE."<<endl;
        else cout<<"NOT BICOLORABLE."<<endl;
    }
    return 0;
}
