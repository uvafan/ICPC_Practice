#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<vi> adjList;
vector<set<int> > brokenCycles;
vi dfs_num, dfs_low, dfs_parent;
vii pigeonCounts;
int rootChildren, dfs_root, dfs_counter;

void articulationPoint(int u){
    dfs_counter++;
    dfs_low[u] = dfs_num[u] = dfs_counter;
    for(int i=0;i<adjList[u].size();i++){
        int v = adjList[u][i];
        //cout << "u = " << u << " v = " << v << endl;
        if(!dfs_num[v]){
            dfs_parent[v] = u;
            if(u==dfs_root)rootChildren++; //cout << "inc" << endl;}
            articulationPoint(v);
            if(dfs_low[v] >= dfs_num[u]) brokenCycles[u].insert(dfs_low[v]);
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    int V,i,j,numStations;
    while(1){
        cin >> V >> numStations;
        if(!V&&!numStations)break;
        brokenCycles.clear();
        pigeonCounts.clear();
        for(i=0;i<V;i++){
            set<int> tA;
            brokenCycles.push_back(tA);
        }
        dfs_counter = 0; dfs_num.assign(V,0); dfs_low.assign(V,0);
        dfs_parent.assign(V,0); adjList.assign(V,vi(0,0));
        int a,b;
        while(1){
            cin >> a >> b;
            if(a==-1)break;
            adjList[a].push_back(b);
            adjList[b].push_back(a);
        }
        for(i=0;i<V;i++){
            if(!dfs_num[i]){
                dfs_root=i;rootChildren=0;articulationPoint(i);
                pigeonCounts.push_back(make_pair(INF-rootChildren,dfs_root));
            }
        }
        int numToCheck = pigeonCounts.size();
        for(i=0;i<V;i++){
            bool flag = true;
            for(j=0;j<numToCheck;j++){
                if(pigeonCounts[j].second==i){
                    flag = false;
                    break;
                }
            }
            if(flag)
                pigeonCounts.push_back(make_pair(INF-brokenCycles[i].size()-1,i));
        }
        sort(pigeonCounts.begin(),pigeonCounts.end());
        for(i=0;i<numStations;i++){
            cout << pigeonCounts[i].second << " " << INF-pigeonCounts[i].first << endl;
        }
        cout << endl;
    }
    return 0;
}
