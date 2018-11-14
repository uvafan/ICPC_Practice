#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1000000000

vector<vi> adjList;
int N,j;
vii height;
vi rootHeight;
vi vis;

int calcHeight(int u){
    if(vis[u])
        return -INF;
    //cout<<"u: "<<u<<endl;
    vis[u]=1;
    for(int i=0;i<adjList[u].size();i++){
        //cout<<"u: "<<u<<" v: "<<adjList[u][i]<<endl;
        int h = calcHeight(adjList[u][i])+1;
        //cout<<"u: "<<u<<" v: "<<adjList[u][i]<<" "<<h<<endl;
        if(h>height[u].first){
            height[u].second = height[u].first;
            height[u].first = h;
        }
        else if(h>height[u].second){
            height[u].second = h;
        }
    }
    //cout<<u<<": "<<height[u].first<<" "<<height[u].second<<endl;
    return height[u].first;
}

void calcRootHeight(int u, int bestOpt){
    if(vis[u])
        return;
    vis[u]=1;
    rootHeight[u] = max(bestOpt,height[u].first);
    for(int i=0;i<adjList[u].size();i++){
        int v = adjList[u][i];
        int bestAltHeight = height[u].first;
        if(height[v].first+1==height[u].first)
            bestAltHeight = height[u].second;
        calcRootHeight(v, max(bestOpt+1,bestAltHeight+1));
    }
}

int main(){
    while(cin>>N){
        vis.assign(N,0);
        adjList.assign(N,vi(0,0));
        height.assign(N,ii(1,0));
        rootHeight.assign(N,0);
        int n;
        int i;
        for(i=0;i<N;i++){
            cin>>n;
            while(n--){
                cin>>j;
                adjList[i].pb(j-1);
            }
        }
        calcHeight(0);
        vis.assign(N,0);
        calcRootHeight(0,1);
        int minHeight = INF;
        int maxHeight = -INF;
        vi best(0,0);
        vi worst(0,0);
        for(i=0;i<N;i++){
            minHeight = min(minHeight,rootHeight[i]);
            maxHeight = max(maxHeight,rootHeight[i]);
        }
        cout<<"Best Roots  :";
        for(i=0;i<N;i++){
            //cout<<"rh of "<<i<< " is "<<rootHeight[i]<<endl;
            if(rootHeight[i]==minHeight)
                cout<<" "<<i+1;
        }
        cout<<endl<<"Worst Roots :";
        for(i=0;i<N;i++){
            if(rootHeight[i]==maxHeight)
                cout<<" "<<i+1;
        }
        cout<<endl;
    }
    return 0;
}
