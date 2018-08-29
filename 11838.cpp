#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<vi> adjList;
vi visited, dfs_low, dfs_num, S;
int dfsNumberCounter, sccs;

void SCC(int u){
    dfsNumberCounter++;
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    S.push_back(u);
    visited[u] = 1;
    for(int i=0;i<adjList[u].size();i++){
        int v = adjList[u][i];
        if(!dfs_num[v])SCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        vi toAdd;
        while(1){
            int v = S.back(); S.pop_back(); visited[v]=0;
            if(u==v)break;
        }
        sccs++;
    }
}

int main(){
    int i,j,V,E,a,b, c;
    while(1){
        cin >> V >> E;
        if(!V&&!E)break;
        adjList.assign(V,vi(0,0));
        while(E--){
            cin >> a >> b >> c;
            adjList[a-1].push_back(b-1);
            if(c==2)
                adjList[b-1].push_back(a-1);
        }
        dfs_num.assign(V,0);dfs_low.assign(V,0);visited.assign(V,0);
        dfsNumberCounter = 0;
        sccs=0;
        for(i=0;i<V;i++)
            if(!dfs_num[i]){
                SCC(i);
            }
        if(sccs==1)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
