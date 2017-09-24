#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<set<int> > adjList;
vi dfs_num, dfs_low, dfs_parent;
vii bridges;
int dfs_counter;

void articulationBridge(int u){
    dfs_counter++;
    dfs_low[u] = dfs_num[u] = dfs_counter;
    for(auto it = adjList[u].begin(); it != adjList[u].end(); it++){
        int v = *it;
        //cout << "u = " << u << " v = " << v << endl;
        if(!dfs_num[v]){
            dfs_parent[v] = u;
            articulationBridge(v);
            if(dfs_low[v] > dfs_num[u]) {
                bridges.push_back(make_pair(min(u,v),max(u,v)));
            }
            dfs_low[u] = min(dfs_low[u], dfs_low[v]);
        }
        else if(v != dfs_parent[u])
            dfs_low[u] = min(dfs_low[u], dfs_num[v]);
    }
}

int main(){
    int V,i,j;
    while(cin>>V){
        adjList.clear();
        if(V<2){
            cout << "0 critical links" << endl << endl;
            continue;
        }
        for(i=0;i<V;i++){
            set<int> s;
            adjList.push_back(s);
        }
        dfs_counter = 0; dfs_num.assign(V,0); dfs_low.assign(V,0);
        dfs_parent.assign(V,0); bridges.clear();
        int a,b;
        for(i=0;i<V;i++){
            cin >> a;
            string s;
            cin >> s;
            int conns = stoi(s.substr(1,s.size()-2));
            while(conns--){
                cin >> b;
                adjList[a].insert(b);
            }
        }
        for(i=0;i<V;i++){
            if(!dfs_num[i]){
                articulationBridge(i);
            }
        }
        int ret = 0;
        cout << bridges.size() << " critical links" << endl;
        sort(bridges.begin(),bridges.end());
        for(i=0;i<bridges.size();i++){
            ii b = bridges[i];
            cout << b.first << " - " << b.second << endl;
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}
