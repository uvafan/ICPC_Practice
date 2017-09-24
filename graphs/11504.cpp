#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<vi> adjList, adjListSCCS, sccs;
vi visited, dfs_low, dfs_num, S, indegree, sccID;
int dfsNumberCounter;

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
            toAdd.push_back(v);
            sccID[v] = sccs.size();
            if(u==v)break;
        }
        sccs.push_back(toAdd);
    }
}

int main(){
    int i,j,V,E,N,a,b;
    cin>>N;
    while(N--){
        cin >> V >> E;
        adjList.assign(V,vi(0,0));
        while(E--){
            cin >> a >> b;
            adjList[a-1].push_back(b-1);
        }
        dfs_num.assign(V,0);dfs_low.assign(V,0);visited.assign(V,0);
        dfsNumberCounter = 0; sccID.assign(V,0);
        sccs.clear();
        for(i=0;i<V;i++)
            if(!dfs_num[i]){
                SCC(i);
            }
        vi sccIndegree(sccs.size(),0);
        for(i=0;i<sccs.size();i++){
            for(int k=0;k<sccs[i].size();k++){
                int v = sccs[i][k];
                for(j=0;j<adjList[v].size();j++){
                    if(sccID[adjList[v][j]]!=i)
                        sccIndegree[sccID[adjList[v][j]]]++;
                }
            }
        }
        int count = 0;
        for(i=0;i<sccIndegree.size();i++)
            if(!sccIndegree[i])
                count++;
        cout << count << endl;
    }
    return 0;
}
