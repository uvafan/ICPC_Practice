#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1000000000

int main(){
    int V;
    int count=0;
    while(cin>>V){
        if(count)cout<<endl;
        count++;
        vector<vi> adjList(V,vi(0,0));
        vi indegree(V,0);
        vi death(V,1);
        vi paths(V,0);
        int n;
        for(int i=0;i<V;i++){
            cin>>n;
            if(n) death[i]=0;
            int u;
            while(n--){
                cin>>u;
                adjList[i].pb(u);
                indegree[u]++;
            }
        }
        paths[0]=1;
        queue<int> q;
        q.push(0);
        paths[0]=1;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(int j=0;j<adjList[u].size();j++){
                int v = adjList[u][j];
                paths[v]+=paths[u];
                indegree[v]--;
                if(!indegree[v])
                    q.push(v);
            }
        }
        int ret = 0;
        for(int i=0;i<V;i++){
            if(death[i])
                ret+=paths[i];
        }
        cout<<ret<<endl;
    }
    return 0;
}
