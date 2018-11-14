#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
#define INF 1000000000

vector<set<int> > adjList;
vector<vi> sccs;
unordered_map<string,int> stoin;
vector<string> names;
vi visited, dfs_low, dfs_num, S;
int dfsNumberCounter;

void SCC(int u){
    dfsNumberCounter++;
    dfs_low[u] = dfs_num[u] = dfsNumberCounter;
    S.push_back(u);
    visited[u] = 1;
    //cout << names[u] << " has list of size " << adjList[u].size() << endl;
    for(auto it = adjList[u].begin(); it!=adjList[u].end(); it++){
        int v = *it;
       // cout << "going from " << names[u] << " to " << names[v] << endl;
        if(!dfs_num[v])SCC(v);
        if(visited[v])
            dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    }
    if(dfs_low[u] == dfs_num[u]){
        vi toAdd;
        while(1){
            int v = S.back();
            toAdd.push_back(v); S.pop_back(); visited[v]=0;
            if(u==v)break;
        }
        sccs.push_back(toAdd);
    }
}

int main(){
    int i,j,V,E;
    int dataset = 1;
    while(1){
        cin >> V >> E;
        if(!V&&!E)break;
        if(dataset>1)cout<<endl;
        stoin.clear();
        names.clear();
        string a,b;
        adjList.clear();
        for(i=0;i<V;i++){
            set<int> se;
            adjList.push_back(se);
        }
        while(E--){
            cin >> a >> b;
            //cout << "a=" << a << " b=" << b << endl;
            unordered_map<string,int>::const_iterator gota = stoin.find(a);
            if(gota == stoin.end()){
                stoin[a] = names.size();
                names.push_back(a);
            }
            unordered_map<string,int>::const_iterator gotb = stoin.find(b);
            if(gotb == stoin.end()){
                stoin[b] = names.size();
                names.push_back(b);
            }
            //cout << "a=" << stoin[a] << "b=" << stoin[b] << endl;
            //cout << names[stoin[a]] << " " << names[stoin[b]] << endl; 
            adjList[stoin[a]].insert(stoin[b]);
            //if(adjList.size()>2)
              //  cout << "BSize = " << adjList[2].size() << endl;
        }
        dfs_num.assign(V,0);dfs_low.assign(V,0);visited.assign(V,0);
        dfsNumberCounter = 0; sccs.clear();
        for(i=0;i<V;i++)
            if(!dfs_num[i]){
                S.clear();
                SCC(i);
            }
        cout << "Calling circles for data set " << dataset << ":\n";
        for(i=0;i<sccs.size();i++){
            for(j=0;j<sccs[i].size();j++){
                cout << names[sccs[i][j]];
                if(j<sccs[i].size()-1)cout<<", ";
            }
            cout << endl;
        }
        dataset++;
    }
    return 0;
}
