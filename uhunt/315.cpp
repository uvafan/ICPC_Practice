#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<set<int> > adjList;
vi dfs_num, dfs_low, articulation_vertex, dfs_parent;
int rootChildren, dfs_root, dfs_counter;

void articulationPoint(int u){
    dfs_counter++;
    dfs_low[u] = dfs_num[u] = dfs_counter;
    for(auto it = adjList[u].begin(); it != adjList[u].end(); it++){
        int v = *it;
        //cout << "u = " << u << " v = " << v << endl;
        if(!dfs_num[v]){
            dfs_parent[v] = u;
            if(u==dfs_root)rootChildren++; //cout << "inc" << endl;}
            articulationPoint(v);
            if(dfs_low[v] >= dfs_num[u]) articulation_vertex[u]=1;
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    int V,i,j;
    while(1){
        adjList.clear();
        cin >> V;
        if(!V)break;
        for(i=0;i<V;i++){
            set<int> s;
            adjList.push_back(s);
        }
        dfs_counter = 0; dfs_num.assign(V,0); dfs_low.assign(V,0);
        dfs_parent.assign(V,0); articulation_vertex.assign(V,0);
        int a,b;
        while(1){
            cin >> a;
            if(!a)break;
            while(cin.peek()!='\n'){
                cin >> b;
                adjList[a-1].insert(b-1);
                adjList[b-1].insert(a-1);
            }
        }
        for(i=0;i<V;i++){
            if(!dfs_num[i]){
                dfs_root=i;rootChildren=0;articulationPoint(i);
                if(rootChildren>1){
                    articulation_vertex[dfs_root] = 1; 
                }
                else{
                    articulation_vertex[dfs_root] = 0;
                }
            }
        }
        int ret = 0;
        for(i=0;i<V;i++){
            if(articulation_vertex[i]){
                //cout << i << endl;
                ret++;
            }
        }
        cout << ret << endl;
    }
    return 0;
}
