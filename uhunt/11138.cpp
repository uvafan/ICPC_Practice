#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1e9

vi match,vis;
int N,i,j,n,b;
vector<vi> adjList;

int Aug(int l){
    if(vis[l]) return 0;
    vis[l]=1;
    for(int k=0;k<adjList[l].size();k++){
        int r = adjList[l][k];
        if(match[r]==-1||Aug(match[r])){
            match[r]=l; return 1;
        }
    }
    return 0;
}

int main(){
    cin>>N;
    for(int ca=1;ca<=N;ca++){
        cin>>n>>b;
        adjList.assign(n+b,vi(0,0));
        for(i=0;i<n;i++){
            for(j=0;j<b;j++){
                int w;
                cin>>w;
                if(w){
                    adjList[i].pb(j+n);
                    adjList[j+n].pb(i);
                }
            }
        }
        int ans=0;
        match.assign(n+b,-1);
        for(int l=0;l<n;l++){
            vis.assign(n,0);
            ans+=Aug(l);
        }
        cout<<"Case "<<ca<<": a maximum of "<<ans<<" nuts and bolts can be fitted together"<<endl;
    }
    return 0;
}
