#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

#define pb push_back
#define INF 1000000000

list<int> cyc;
int N,i,T;
vector<vii> adjList;

void EulerTour(list<int>::iterator it, int u){
    //cout<<u<<endl;
    for(int j=0;j<adjList[u].size();j++){
        ii v = adjList[u][j];
        //cout<<"v.f "<<v.first<<" v.s "<<v.second<<endl;
        if(v.second){
            adjList[u][j].second = 0;
            for(int k=0;k<adjList[v.first].size();k++){
                ii uu = adjList[v.first][k];
                if(uu.first==u && uu.second){
                    adjList[v.first][k].second=0;
                    break;
                }
            }
            EulerTour(cyc.insert(it,u),v.first);
        }
    }
}

int main(){
    cin>>T;
    int ca=0;
    while(T--){
        ca++;
        cin>>N;
        adjList.assign(50,vii(0,ii(0,0)));
        vi degree(50,0);
        int u,v;
        while(N--){
            cin>>u>>v; u--; v--;
            adjList[u].pb(ii(v,1));
            adjList[v].pb(ii(u,1));
            degree[u]++;
            degree[v]++;
        }
        bool tour = true;
        int start = -1;
        for(i=0;i<50;i++){
            if(degree[i]%2==1){
                tour=false;
                break;
            }
            if(degree[i]&&start==-1)
                start=i;
        }
        cout<<"Case #"<<ca<<endl;
        if(tour){
            cyc.clear();
            EulerTour(cyc.begin(),start);
            int last = -1;
            int first = -1;
            int cur;
            for(auto it=cyc.begin();it!=cyc.end();it++){
                cur = *it;
                //cout<<cur<<endl;
                if(last>-1){
                    cout<<last+1<<" "<<cur+1<<endl;
                }
                else{
                    first = cur;
                }
                last=cur;
            }
            cout<<last+1<<" "<<first+1<<endl;
        }
        else{
            cout<<"some beads may be lost"<<endl;
        }
        if(T>0)
            cout<<endl;
    }
    return 0;
}
